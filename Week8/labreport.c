#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 10

// Shared counter
int counter = 1;
// Mutex for thread synchronization
pthread_mutex_t mutex;

// Function executed by both threads
void* display_numbers(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex); // Lock the mutex

        if (counter > MAX_NUM) { // Stop condition
            pthread_mutex_unlock(&mutex); // Unlock before exiting
            break;
        }

        printf("Thread %ld: %d\n", (long)arg, counter); // Print the number
        counter++; // Increment the counter

        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, display_numbers, (void*)1);
    pthread_create(&thread2, NULL, display_numbers, (void*)2);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}


#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function executed by the first thread
void* find_primes_thread1(void* arg) {
    for (int i = 1; i <= 250; i++) {
        if (is_prime(i)) {
            printf("Thread 1: %d\n", i);
        }
    }
    return NULL;
}

// Function executed by the second thread
void* find_primes_thread2(void* arg) {
    for (int i = 251; i <= 500; i++) {
        if (is_prime(i)) {
            printf("Thread 2: %d\n", i);
        }
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create the two threads
    pthread_create(&thread1, NULL, find_primes_thread1, NULL);
    pthread_create(&thread2, NULL, find_primes_thread2, NULL);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("All prime numbers from 1 to 500 have been displayed.\n");

    return 0;
}


#include <stdio.h>
#include <pthread.h>

// Function executed by each thread
void* display_numbers(void* arg) {
    int thread_id = *(int*)arg; // Get the thread's ID
    int start = (thread_id - 1) * 200 + 1; // Calculate the start of the range
    int end = thread_id * 200;            // Calculate the end of the range

    for (int i = start; i <= end; i++) {
        printf("Thread %d: %d\n", thread_id, i);
    }

    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, display_numbers, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All numbers from 1 to 1000 have been displayed.\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold thread arguments
typedef struct {
    int thread_id;
    int start;
    int end;
} ThreadData;

// Function executed by each thread
void* display_numbers(void* arg) {
    ThreadData* data = (ThreadData*)arg; // Cast argument to ThreadData
    for (int i = data->start; i <= data->end; i++) {
        printf("Thread %d: %d\n", data->thread_id, i);
    }
    return NULL;
}

int main() {
    int num_threads;

    // Get the number of threads from the user
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Validate input
    if (num_threads <= 0) {
        printf("Number of threads must be greater than 0.\n");
        return 1;
    }

    pthread_t* threads = malloc(num_threads * sizeof(pthread_t)); // Dynamically allocate thread array
    ThreadData* thread_data = malloc(num_threads * sizeof(ThreadData)); // Dynamically allocate thread data array

    int range_size = 1000 / num_threads; // Calculate the range size each thread will handle
    int remaining = 1000 % num_threads;  // Handle any leftover numbers

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].start = i * range_size + 1;
        thread_data[i].end = (i + 1) * range_size;

        // Distribute the remainder to the last thread
        if (i == num_threads - 1) {
            thread_data[i].end += remaining;
        }

        pthread_create(&threads[i], NULL, display_numbers, &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All numbers from 1 to 1000 have been displayed.\n");

    // Free dynamically allocated memory
    free(threads);
    free(thread_data);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold thread arguments
typedef struct {
    int thread_id;
    int start;
    int end;
} ThreadData;

// Function executed by each thread
void* display_odd_numbers(void* arg) {
    ThreadData* data = (ThreadData*)arg; // Cast argument to ThreadData
    for (int i = data->start; i <= data->end; i++) {
        if (i % 2 != 0) { // Check if the number is odd
            printf("Thread %d: %d\n", data->thread_id, i);
        }
    }
    return NULL;
}

int main() {
    int num_threads;

    // Get the number of threads from the user
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Validate input
    if (num_threads <= 0) {
        printf("Number of threads must be greater than 0.\n");
        return 1;
    }

    pthread_t* threads = malloc(num_threads * sizeof(pthread_t)); // Dynamically allocate thread array
    ThreadData* thread_data = malloc(num_threads * sizeof(ThreadData)); // Dynamically allocate thread data array

    int range_size = 1000 / num_threads; // Calculate the range size each thread will handle
    int remaining = 1000 % num_threads;  // Handle any leftover numbers

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].start = i * range_size + 1;
        thread_data[i].end = (i + 1) * range_size;

        // Distribute the remainder to the last thread
        if (i == num_threads - 1) {
            thread_data[i].end += remaining;
        }

        pthread_create(&threads[i], NULL, display_odd_numbers, &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All odd numbers from 1 to 1000 have been displayed.\n");

    // Free dynamically allocated memory
    free(threads);
    free(thread_data);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// Structure to hold thread arguments
typedef struct {
    int thread_id;
    int* array;
    int start;
    int end;
    int target;
    bool* found;
    pthread_mutex_t* mutex;
} ThreadData;

// Function executed by each thread
void* search_element(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    for (int i = data->start; i <= data->end; i++) {
        // Check if the target is found
        if (data->array[i] == data->target) {
            pthread_mutex_lock(data->mutex);
            *(data->found) = true; // Update the shared found flag
            pthread_mutex_unlock(data->mutex);
            return NULL;
        }
    }

    return NULL;
}

int main() {
    int n, num_threads, target;
    bool found = false;

    // Get the array size and number of threads
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int* array = malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads <= 0) {
        printf("Number of threads must be greater than 0.\n");
        free(array);
        return 1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    ThreadData* thread_data = malloc(num_threads * sizeof(ThreadData));
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    int range_size = n / num_threads; // Calculate range size
    int remaining = n % num_threads; // Handle remaining elements

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].array = array;
        thread_data[i].start = i * range_size;
        thread_data[i].end = (i + 1) * range_size - 1;
        thread_data[i].target = target;
        thread_data[i].found = &found;
        thread_data[i].mutex = &mutex;

        // Handle the remaining elements in the last thread
        if (i == num_threads - 1) {
            thread_data[i].end += remaining;
        }

        pthread_create(&threads[i], NULL, search_element, &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    if (found) {
        printf("Element found.\n");
    } else {
        printf("Element not found.\n");
    }

    // Free allocated memory
    free(array);
    free(threads);
    free(thread_data);

    return 0;
}
