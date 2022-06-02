// Mutex-Timed_Lock

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int count = 0;
pthread_mutex_t mutex_count;

void *incThread(void *);
void *decThread(void *);

void *incThread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_count);
        count++;
        printf("Inc sleeping\n");
        sleep(5);
        printf("Inc Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}

void *decThread(void *arg)
{
    int res = 0;
    while (1)
    {   
        int res = 0;
       
        struct timespec *wait;
        wait=(struct timespec *)(malloc(sizeof(struct timespec)));
        wait->tv_sec=5;
        wait->tv_nsec=0;
       
        sleep(5);
        res = pthread_mutex_timedlock(&mutex_count, wait);
        if(res!=0)
        {
        perror("Wait timed out"); 
        }
        else
        {
        printf("result=%d\n",res);
        count--;
        printf("Dec Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
        }
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
