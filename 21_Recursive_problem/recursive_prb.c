#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex_count;

void *incThread(void *);
void *decThread(void *);

void *incThread(void *arg)
{
    while (1)
    {
        printf("Inc Lock:first time\n");
        pthread_mutex_lock(&mutex_count);
        printf("Inc Lock:second time\n");
        pthread_mutex_lock(&mutex_count);
        count++;
        
        pthread_mutex_unlock(&mutex_count);
        printf("Inc unLocked:first time\n");
        pthread_mutex_unlock(&mutex_count);
        printf("Inc unlocked:second time\n");
    }
}

void *decThread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_count);
        count--;
        printf("Dec Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}

int main(int argc,char const *argv[])
{
    pthread_t inc, dec;
    pthread_mutex_init(&mutex_count,NULL);
    pthread_create(&inc, NULL, incThread, NULL);
    pthread_create(&dec, NULL, decThread, NULL);
    pthread_join(inc, NULL);
    pthread_join(dec, NULL);
    pthread_mutex_destroy(&mutex_count);
    return 0;
}
