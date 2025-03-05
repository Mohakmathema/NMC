#include <stdio.h>
#include <pthread.h>
int shared = 10;
pthread_mutex_t L;

void *T1(void *p)
{
    int x;
    pthread_mutex_lock(&L);
    x = shared;
    x = x + 2;
    shared = x;
    pthread_mutex_unlock(&L);
}
void *T2(void *p)
{
    int y;
    pthread_mutex_lock(&L);
    y = shared;
    y = y - 4;
    shared = y;
    pthread_mutex_unlock(&L);
}
void main()
{
    pthread_mutex_init(&L, NULL);
    pthread_t id1, id2;
    pthread_create(&id1, NULL, T1, NULL);
    pthread_create(&id2, NULL, T2, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    printf("%d", shared);
}