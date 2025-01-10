// #include<stdio.h>
// #include "lodepng.h"
// int main(){
//     unsigned char *image;
//     unsigned int width, height;
//     lodepng_decode32_file(&image, &width, &height, "image.png");
//     for(int i = 0; i<width*height*4; i+=4){
//         unsigned int average = (image[i]+image[i+1]+image[i+2])/3;
//         image[i] = average;
//         image[i+1] = average;
//         image[i+2] = average;
//     }
//     lodepng_encode32_file("image2.png", image, width, height);
// }

#include<stdio.h>
#include "lodepng.h"
int main(){
    unsigned char *image;
    unsigned int width, height;
    lodepng_decode32_file(&image, &width, &height, "image.png");
    for(int i = 0; i<width*height*4; i+=4){
        image[i] = 255-image[i];
        image[i+1] = 255-image[i+1];
        image[i+2] = 255-image[i+2];
    }
    lodepng_encode32_file("image1.png", image, width, height);
}