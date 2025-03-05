#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "lodepng.h"
#define THREAD_COUNT 4 //no of threads

unsigned char* image;       
unsigned char* blurredImage; 
unsigned width, height;     
void applyGaussianBlur(int x, int y) {
    float kernel[3][3] = { //3x3 gausian kernel matrix to apply blur, emphasizing center pixel while avg surrounding pixel
        {1, 2, 1},
        {2, 4, 2}, //center is 4 here
        {1, 2, 1}
    };
    float sumR = 0, sumG = 0, sumB = 0; //weighted sum of RGB vals
    //* for top and left pixels as i=row and j=cols
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i; //calc coords of surrounding pixels, x-center pixl
            int newY = y + j; //calc coords of surrounding pixels y=center pixel
            
            if (newX >= 0 && newX < width && newY >= 0 && newY < height) { //*making sure the width and height does not go beyond the images width and height
                int index = (newY * width + newX) * 4; //1D array index
                /*
                newy*width=moves to correct row
                newX=moves to correct column
                ** *4 cuz RGBT
                */
                float weight = kernel[i + 1][j + 1]; //gets gausian blur from kernal for center element
                //*applying gausian blur formula:
                sumR += image[index] * weight;
                sumG += image[index + 1] * weight;
                sumB += image[index + 2] * weight;  
            }
        }
    }
    int index = (y * width + x) * 4; //*y*width=no.of pixels in given row and x=current cols num 
    //*accessing RGBA from pixel:
    blurredImage[index] = (unsigned char)(sumR / 16.0);
    blurredImage[index + 1] = (unsigned char)(sumG / 16.0);
    blurredImage[index + 2] = (unsigned char)(sumB / 16.0);
    blurredImage[index + 3] = image[index + 3]; //alpha preserve val to opaque
}

//creating thread function
//*
void* threadFunction(void* arg) {
    int threadId = *(int*)arg; //conv void to int
    int startRow = (height / THREAD_COUNT) * threadId;
    int endRow = (threadId == THREAD_COUNT - 1) ? height : (height / THREAD_COUNT) * (threadId + 1);

    //*loops through the rows and applies gauisan blur function to each pixel
    for (int y = startRow; y < endRow; y++) {
        for (int x = 0; x < width; x++) {
            applyGaussianBlur(x, y);
        }
    }
    return NULL;
}

int main() {
    //decoding the image into RGB vals
    unsigned error = lodepng_decode32_file(&image, &width, &height, "image.png");
    if (error) { //error handling for image decodinf
        fprintf(stderr, "Error %u: %s\n", error, lodepng_error_text(error));
        return 1;
    }

    blurredImage = malloc(width * height * 4); //allocating memory for the blurred image same size as original
    pthread_t threads[THREAD_COUNT]; //arr to store thread id
    int threadIds[THREAD_COUNT]; //*

    //create threads to apply Gaussian blur in parallel //*
    for (int i = 0; i < THREAD_COUNT; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
    }
    //waiting for all thread to finish and then joining them together
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL); //no return value
    }

    error = lodepng_encode32_file("blurred_image.png", blurredImage, width, height);
    if (error) {
        //*
        fprintf(stderr, "Error %u: %s\n", error, lodepng_error_text(error));
        free(image);
        free(blurredImage);
        return 1; 
    }
    free(image);         
    free(blurredImage);  
    printf("Successfully applied blur to blured_image.png");
    return 0;
}