#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

#define OUTPUT_FILE "primes_output.txt" //,aking macro for output file

//array of files hardcoded:
const char *file_names[] = {"PrimeData1.txt", "PrimeData2.txt", "PrimeData3.txt"};
//getting size of file_name arr=3*8 bytes/8 bytes
const int num_files = sizeof(file_names) / sizeof(file_names[0]); //gives no of files

int *numbers = NULL;
int *primes = NULL;
int total_numbers = 0;
int prime_count = 0;
int num_threads;
pthread_mutex_t mutex; //initializing before to avoid undefined behaviour

//this function checks if a number is prime
bool is_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    //checking for sqrt of the number cuz to decrease the number of iterations also the iterations after the sqrt the factors repeat in reverse
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Thread function to process a slice of numbers
void *find_primes(void *arg) {
    //casting the type of thread_id to be int by dereferencing it to ensure which part of arr the thread should process
    int thread_id = *(int *)arg;
    int start = (total_numbers / num_threads) * thread_id; //current thread begins work in arr
    int end = (thread_id == num_threads - 1) ? total_numbers : (total_numbers / num_threads) * (thread_id + 1); //current thread stops processing

    for (int i = start; i < end; i++) {
        if (is_prime(numbers[i])) {
            pthread_mutex_lock(&mutex); //locking the mutex to prevent access/modification by other thread id's to prevent race condition
            primes[prime_count++] = numbers[i]; //putting the current iteration of num into primes arr while also incrementing prime count
            pthread_mutex_unlock(&mutex);
        }
    }
    pthread_exit(NULL); //exiting the pthread with no return value
}

int main() {
    // Get number of threads from user
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);
    if (num_threads <= 0) {
        printf("Number of threads must be positiv \n");
        return 1;
    }

    //read numbers from the 3files
    FILE *file;
    for (int i = 0; i < num_files; i++) {
        file = fopen(file_names[i], "r");
        if (!file) {
            printf("Cannot open file %s\n", file_names[i]);
            return 1;
        }
        int num;
        while (fscanf(file, "%d", &num) == 1) { //checking the return value/amount
            total_numbers++;
        }
        fclose(file); //closing the file to prevent mem leak
    }

    //alocate memory
    numbers = malloc(total_numbers * sizeof(int));
    primes = malloc(total_numbers * sizeof(int));
    if (!numbers || !primes) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    //loading teh numbers into array
    int index = 0;
    for (int i = 0; i < num_files; i++) {
        file = fopen(file_names[i], "r");
        while (fscanf(file, "%d", &numbers[index]) == 1) {
            index++;
        }
        fclose(file);
    }
    // Create threads
    pthread_t threads[num_threads];
    int thread_ids[num_threads]; //creating thread id with no of threads
    pthread_mutex_init(&mutex, NULL); //initializing mutex to be ready to use and prevent threads simultaneously accessing shared data,
    // NUll=default attributes
    
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i; //giving thread unique id corresponding to their index in loop
        if (pthread_create(&threads[i], NULL, find_primes, &thread_ids[i]) != 0) { //default thread attributes
            printf("Error: Failed to create thread %d\n", i);
            return 1;
        }
    }
    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    
    // Write prime numbers to output file
    file = fopen(OUTPUT_FILE, "w");
    if (!file) {
        printf("Error: Cannot open output file.\n");
        return 1;
    }
    fprintf(file, "Total prime numbers: %d\n", prime_count);
    for (int i = 0; i < prime_count; i++) {
        fprintf(file, "%d\n", primes[i]);
    }
    fclose(file);

    printf("Prime numbers saved to %s\n", OUTPUT_FILE);
    // Free memory
    free(numbers);
    free(primes);
}