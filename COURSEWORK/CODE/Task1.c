#include <stdio.h>
#include <stdlib.h>

void calcLinearRegression(double x[], double y[], int n, double *a, double *b) { //a=intercept,b=slope
//sumX=sum of all x-vals, sumY=sum of all y-vals, sumXY=sum of product of x&y vals, sumX2=sum of square of x-vals
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    //least squares formula to calculate the intercept(a) and slope(b)
    *a = (sumY * sumX2 - sumX * sumXY) / (n * sumX2 - sumX * sumX);
    *b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
}

/*
    ** fileName=stores name of file
    ** **x=pointer to array where the value is stored
    ** **y=pointer to array where the value is stored
    ** *size=pointer to store the size/number of datapoints
*/
int readDataFromFile(const char *fileName, double **x, double **y, int *size) {
    FILE *file = fopen(fileName, "r");
    //handling error if file cannot be accesssed
    if (file == NULL) {
        printf("Canot open file '%s' \n", fileName);
        return 0;
    }
    
    int n = 0;
    //temp stores line read from file and counts no of lines. reads 256 chars while ensuring space for \0. 
    char buffer[256];
    //reads file line by line with  fgets(), counting the size/datapoint till EOF
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        n++;
    }
    rewind(file); //resets the file pointer to beginning of the file

    //dynamically storing memory using malloc to store values of x and y
    //n stores the no of x and y in file
    double *tempX = malloc(n * sizeof(double));
    double *tempY = malloc(n * sizeof(double));
    //error handling for dynamic memory allocation
    if (tempX == NULL || tempY == NULL) {
        printf("Error: Memory allocation failed.\n");
        //close file
        fclose(file);
        return 0;
    }

    int i = 0;
    //reading from file using fscanf.
    //this reads values with comma separation from the file and stores in array[dynamic]
    while (fscanf(file, "%lf,%lf", &tempX[i], &tempY[i]) == 2) { //checks if both values are successfully read returns 2 for success
        i++;
    }
    fclose(file);

    //error handling if all datapoints were read successfully
    if (i != n) {
        printf("unequal expected and actual vals '%s'.\n", fileName);
        //freeing the memory allocation to prevent memory leak
        free(tempX);
        free(tempY);
        return 0;
    }
    
    //pointing to the values/storing memory address of variables
    *x = tempX;
    *y = tempY;
    *size = n;
    return 1;
}

int main() {
    const char *files[4] = {"datasetLR1.txt", "datasetLR2.txt", "datasetLR3.txt", "datasetLR4.txt"}; //array of files to read
    int totalSize = 0; //total no of datapoints from all file
    double *xAll = NULL, *yAll = NULL;
    
    for (int i = 0; i < 4; i++) { //loop over all 4 files
        double *x = NULL, *y = NULL;
        int size = 0;
        
        //calling func readDataFromFile() to get x and y vals from file
        if (readDataFromFile(files[i], &x, &y, &size)) {
            //dynamic mem allocation using realloc to reallocate the memory
            xAll = realloc(xAll, (totalSize + size) * sizeof(double));
            yAll = realloc(yAll, (totalSize + size) * sizeof(double));
            
            //error handling for dynamic memory allocation
            if (xAll == NULL || yAll == NULL) {
                printf("Error: Memory allocation failed.\n");
                free(x);
                free(y);
                return 1;
            }
            
            //adds new read data into the following xAll and yAll
            for (int j = 0; j < size; j++) {
                //j=current index of current file to make sure data is placed in correct position in larger array
                xAll[totalSize + j] = x[j];
                yAll[totalSize + j] = y[j];
            }
            totalSize += size; //adding size to total size to get new total size
            
            //free memory for individual files
            free(x);
            free(y);
        }
    }
    
    //no data read? this runs:
    if (totalSize == 0) {
        printf("No data available for regression analysis.\n");
        return 1;
    }
    
    //calling the calcLinerarRegression
    double a, b;
    calcLinearRegression(xAll, yAll, totalSize, &a, &b);
    printf("\nCombined Equation of Line: y = %.2fx + %.2f\n", b, a);
    
    double inputX;
    printf("Enter value of x to calculate y: ");
    if (scanf("%lf", &inputX) != 1) { //scanf returns 1 for sucessfully reading 1 value so checking for that
        printf("Error: Invalid input for x.\n");
    } else {
        double resultY = b * inputX + a; //finding y
        printf("x = %.2f, y = %.2f\n", inputX, resultY);
    }
    
    //freeing memory allocation to prevent memory leak
    free(xAll);
    free(yAll);
}