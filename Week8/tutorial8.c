// #include<stdio.h>
// #include<windows.h>
// #include<pthread.h>

// void *fn1(void *arg)
// {
//     while (1)
//     {
//         Sleep(1000);
//         printf("Hello from fn1\n");
//     }
//     return NULL;
// }

// void *fn2(void *arg)
// {
//     printf("Hello from fn2\n");
//     return NULL; // Add return statement
// }

// int main()
// {
//     pthread_t s1, s2;
//     pthread_create(&s1, NULL, fn1, NULL);
//     pthread_create(&s2, NULL, fn2, NULL); // Add NULL argument
//     pthread_join(s1, NULL); // Wait for thread to finish
//     pthread_join(s2, NULL); // Wait for thread to finish
//     return 0;
// }


#include<stdio.h>
#include<windows.h>
#include<pthread.h>

int isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void *func1(){
    for(int i=1; i<=20; i++){
        // printf("%d",i);
        if(isPrime(i)){
            printf("%d is prime\n", i);
        }
        Sleep(1000);
    }
}

void *func2(){
    for(int i=20; i<=50; i++){
        // printf("%d",i);
        if(isPrime(i)){
            printf("%d is prime\n",i);
        }
        Sleep(1000);
    }
}

int main(){
    pthread_t w1, w2;
    pthread_create(&w1, NULL, func1, NULL);
    pthread_create(&w2, NULL, func2, NULL);
    pthread_join(w1, NULL);
    pthread_join(w2, NULL);
    return 0;
}