// Mutex Demo

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

void *incThread(void *);
void *decThread(void *);

int count =0;
sem_t sm_count;

int main()
{ 
    sem_init(&sm_count, 0 , 1);
    pthread_t inc,dec;
    pthread_create(&inc,NULL,incThread,NULL);
    pthread_create(&dec,NULL,decThread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
        
    sem_destroy(&sm_count);
    return 0;
}

void *incThread(void *arg)
{
    while(1)
    {   
        sem_wait(&sm_count); 
        count++;
        printf("Inc Thread : %d\n", count);
        sem_post(&sm_count);
    }
}

void *decThread(void *arg)
{
    while(1)
    {   
        sem_wait(&sm_count);
        count--;
        printf("Dec Thread : %d\n", count);
        sem_post(&sm_count);
    }
}