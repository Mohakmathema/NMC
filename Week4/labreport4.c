// #include <stdio.h>

// int main() {
//     int n, i, sum = 0;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter the elements of the array:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     int *ptr = arr; // Pointer pointing to the first element of the array
//     for (i = 0; i < n; i++) {
//         sum += *(ptr + i); 
//     }
//     printf("The sum of all elements in the array is: %d\n", sum);
// }

// #include <stdio.h>
// int main() {
//     int n, i, key, found = 0;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter the elements of the array:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter the element to search: ");
//     scanf("%d", &key);
//     int *ptr = arr; // Pointer pointing to the first element of the array
//     for (i = 0; i < n; i++) {
//         if (*(ptr + i) == key) { 
//             found = 1;
//             printf("Element %d found at position %d.\n", key,i); // Position is 1-based
//             break;
//         }
//     }
//     if (!found) {
//         printf("Element %d not found in the array.\n", key);
//     }
// }

// 

// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int n, i, max;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int *arr = (int *)malloc(n * sizeof(int));
//     if (arr == NULL) {
//         printf("Memory allocation failed.");
//         return 1; // Exit if allocation fails
//     }
//     printf("Enter the elements of the array:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     max = arr[0];
//     for (i = 1; i < n; i++) {
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//     }
//     printf("The maximum element in the array is: %d\n", max);
//     free(arr);
// }


// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int n, i;
//     printf("Enter the number of elements in the arrays: ");
//     scanf("%d", &n);
//     int *arr1 = (int *)malloc(n * sizeof(int));
//     int *arr2 = (int *)malloc(n * sizeof(int));
//     int *arr3 = (int *)malloc(n * sizeof(int));
//     printf("Enter the elements of the first array:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr1[i]);
//     }
//     printf("Enter the elements of the second array:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr2[i]);
//     }
//     for (i = 0; i < n; i++) {
//         arr3[i] = arr1[i] + arr2[i];
//     }
//     printf("The resulting array (sum of corresponding elements) is:\n");
//     for (i = 0; i < n; i++) {
//         printf("%d ", arr3[i]);
//     }
//     free(arr1);
//     free(arr2);
//     free(arr3);
// }


#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, newSize;
    printf("Enter the initial number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Initial array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("Enter the new size of the array (greater than %d): ", n);
    scanf("%d", &newSize);
    arr = (int *)realloc(arr, newSize * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1; // Exit if reallocation fails
    }
    printf("Enter the new elements of the array:\n");
    for (i = n; i < newSize; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Resized array elements are:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}
