/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr;
    char *charPtr;
    float *floatPtr;
    intPtr = (int *)malloc(sizeof(int));
    charPtr = (char *)malloc(sizeof(char));
    floatPtr = (float *)malloc(sizeof(float));
    if (intPtr == NULL || charPtr == NULL || floatPtr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    *intPtr = 42;
    *charPtr = 'A';
    *floatPtr = 3.14;
    printf("Value of int: %d\n", *intPtr);
    printf("Value of char: %c\n", *charPtr);
    printf("Value of float: %.2f\n", *floatPtr);
    free(intPtr);
    free(charPtr);
    free(floatPtr);
}*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, max;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[0]; // Assume the first element is the maximum
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The maximum value in the array is: %d\n", max);
    free(arr);
}

