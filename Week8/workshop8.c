// #include<stdio.h>
// #include<pthread.h>

// void *func1(void *args){
//     for(int i = 1; i<=500;i++){
//         printf("%d",i);
//     }
// }
// void *func2(void *args){
//     for(int i = 0; i>=501 && i<=1000; i++){
//         printf("%d",i);
//     }
// }

// int main(){
//     pthread_t thread1, thread2;
//     pthread_create(&thread1,NULL,func1,NULL);
//     pthread_create(&thread2,NULL,func2,NULL);
//     pthread_join(thread1,NULL);
//     pthread_join(thread2,NULL);
// }


// #include<stdio.h>
// #include<pthread.h>

// void *func1(void *args){
//     for(int i = 1; i<=200;i++){
//         printf("%d",i);
//     }
//     printf("\n");
// }
// void *func2(void *args){
//   for(int i = 201; i<=400;i++){
//         printf("%d,",i);
//     }
//     printf("\n");
// }
// void *func3(void *args){
//       for(int i = 401; i<=600;i++){
//         printf("%d,",i);
//     }
//     printf("\n");
// }
// void *func4(void *args){
//   for(int i = 601; i<=800;i++){
//         printf("%d,",i);
//     }
//     printf("\n");
// }
// void *func5(void *args){
//   for(int i = 801; i<=1000;i++){
//         printf("%d,",i);
//     }
//     printf("\n");
// }

// int main(){
//     pthread_t thread1, thread2, thread3, thread4, thread5;
//     pthread_create(&thread1,NULL,func1,NULL);
//     pthread_create(&thread2,NULL,func2,NULL);
//     pthread_create(&thread3,NULL,func3,NULL);
//     pthread_create(&thread4,NULL,func4,NULL);
//     pthread_create(&thread5,NULL,func5,NULL);
//     pthread_join(thread1,NULL);
//     pthread_join(thread2,NULL);
//     pthread_join(thread3,NULL);
//     pthread_join(thread4,NULL);
//     pthread_join(thread5,NULL);
// }

// #include <stdio.h>
// #include <pthread.h>
// #include <stdlib.h>
// #define MAX 1000

// typedef struct {
//     int start;
//     int end;
// } ThreadData;

// void* display_numbers(void* arg) {
//     ThreadData* data = (ThreadData*)arg;
//     for (int i = data->start; i <= data->end; i++) {
//         printf("%d,", i);
//     }
// }

// int main() {
//     int num_threads;
//     printf("Enter the number of threads: ");
//     scanf("%d", &num_threads);
//     if (num_threads <= 0) {
//         printf("Invalid number of threads. Exiting.\n");
//         return 1;
//     }
//     pthread_t threads[num_threads];
//     ThreadData thread_data[num_threads];
//     int range = MAX / num_threads; // Divide the range equally
//     int remainder = MAX % num_threads;
//     // Create threads and assign ranges
//     for (int i = 0; i < num_threads; i++) {
//         thread_data[i].start = i * range + 1;
//         thread_data[i].end = (i + 1) * range;
//         // Add the remainder to the last thread
//         if (i == num_threads - 1) {
//             thread_data[i].end += remainder;
//         }
//         if (pthread_create(&threads[i], NULL, display_numbers, &thread_data[i]) != 0) {
//             perror("Failed to create thread");
//             return 1;
//         }
//     }
//     // Wait for all threads to finish
//     for (int i = 0; i < num_threads; i++) {
//         pthread_join(threads[i], NULL);
//     }
// }

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int start;
    int end;
} ThreadData;

void* display_odd_numbers(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->start; i <= data->end; i += 2) { 
        printf("%d, ", i);
    }
    printf("\n");
    return NULL;
}

int main() {
    int num_threads;
    // Prompt the user for the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    // Validate the number of threads
    if (num_threads <= 0) {
        printf("Invalid number of threads. Exiting.\n");
        return 1;
    }
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    // Calculate the total number of odd numbers from 1 to 1000
    int total_odds = (MAX + 1) / 2; // Total odd numbers (e.g., 1, 3, ..., 999)
    int range = total_odds / num_threads; // Divide odd numbers equally among threads
    int remainder = total_odds % num_threads;
    // Create threads and assign ranges
    int current_start = 1; // Start with the first odd number
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = current_start;
        thread_data[i].end = current_start + (range * 2) - 2; // Adjust range for odd numbers
        // Add the remainder to the last thread
        if (i == num_threads - 1) {
            thread_data[i].end += remainder * 2;
        }
        if (pthread_create(&threads[i], NULL, display_odd_numbers, &thread_data[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        current_start = thread_data[i].end + 2; // Update the start for the next thread
    }
    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All odd numbers displayed successfully.\n");
    return 0;
}