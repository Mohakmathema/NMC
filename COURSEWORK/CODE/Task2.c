#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

//global variables to store number of iterations, no of threads, global sum and mutex
long long num_iterations;
int num_threads;
double global_sum = 0.0;
pthread_mutex_t mutex; //mutex=mutual exclusive lock to prevent shared content from enetering race condition

//calculate part of the Leibniz series
void *calculate_pi(void *arg) { //thread function that takes void* argument(pointer to threadID)
    int thread_id = *(int *)arg; //gets thread id from argument to divide workload and work on different part of iteration
    double local_sum = 0.0; //sum for each thread
    
    // Divide workload dynamically among threads
    for (long long i = thread_id; i < num_iterations; i += num_threads) {
        // * -1 cuz alternates betn +ve and -ve as i change for accuracy of formula and converging to pi
        double term = pow(-1, i) / (2 * i + 1); //formula to calc each term of lebinez seroes
        local_sum += term;
    }
    
    //locking mutex so other threads can't modify globalsum while 1 thread is modifying and prevent race cond
    pthread_mutex_lock(&mutex);
    global_sum += local_sum;
    pthread_mutex_unlock(&mutex); //ublocking the mutex to allow other threads to access    
    
    pthread_exit(NULL);// *endinig the calling thread to prevent resource/mem leakage
}

int main() {
    //taking user input for no of inters and no of threads
    printf("Enter number of iterations: ");
    scanf("%lld", &num_iterations);
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);
    
    //condition to check if input is negative or not
    if (num_iterations <= 0 || num_threads <= 0) {
        printf("Error: Number of iterations and threads must be positive.\n");
        return 1;
    }
    
    // create array to store thread to manage multiple threads
    pthread_t threads[num_threads];
    //create array to store thread id to manage multiple threads    
    int thread_ids[num_threads];
    //initializing mutex before thread creation
    pthread_mutex_init(&mutex, NULL);
    
    //*parallalism
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i; //assigns unique id to thread to ensure each thread knows which part of work to do
        /*
        *pthread_create=creates a nwe thread in program
        *&threds[i]=mem location where thread id is stored
        *NULL=thread attributes(default)
        *calculate_pi=func that each thread runs
        *thread_ids[i]=pointer to thread ID, to identify workload
        */
        if (pthread_create(&threads[i], NULL, calculate_pi, &thread_ids[i]) != 0) { //returns 0 if success
            printf("Error: Failed to create thread %d\n", i);
            return 1;
        }
    }
    
    //after all threads are finished join them together makes main thread wait for completion of all threads 
    //* no return value/type
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex); //destroying mutex after use to prevent mem leak, resource managemetn
    
    //calc pi by * global_sum with 4 cuz lebinez do pi/4
    double pi = global_sum * 4;
    printf("Estimated value of Pi: %.15f\n", pi);
    
}