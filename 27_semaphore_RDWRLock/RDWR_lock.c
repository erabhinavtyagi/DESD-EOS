// Prgram to demonstrate working of Read-Write Lock.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int count =0;
pthread_rwlock_t count_rwlock;

void *reader1(void *data)
{
int z;
printf("Reader 1: Entering Critical Section\n");
pthread_rwlock_rdlock(&count_rwlock);
printf("Reader 1: Inside Critical Section\n");
z = count + 10;
printf("Reader 1: %d\n", count);
pthread_rwlock_unlock(&count_rwlock);
printf("Reader 1: Left Critical Section\n");
}

void *reader2(void *data)
{
int x;
printf("Reader 2: Entering Critical Section\n");
pthread_rwlock_rdlock(&count_rwlock);
printf("Reader 2: Inside Critical Section\n");
x = count + 40;
printf("Reader 2: %d\n", count);
pthread_rwlock_unlock(&count_rwlock);
printf("Reader 2: Left Critical Section\n");
}

void *writer1(void *data)
{
printf("Writer 1: Entering Critical Section\n");
pthread_rwlock_rdlock(&count_rwlock);
printf("Writer 1: Inside Critical Section\n");
count++;
printf("Writer 1: %d\n", count);
pthread_rwlock_unlock(&count_rwlock);
printf("Writer 1: Left Critical Section\n");
}

int main()
{
    pthread_t r1,r2,w1;

    pthread_rwlock_init(&count_rwlock,NULL);

    pthread_create(&r1,NULL,reader1,NULL);
    pthread_create(&r2,NULL,reader2,NULL);
    pthread_create(&w1,NULL,writer1,NULL);
    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);
    
    pthread_rwlock_destroy(&count_rwlock);       
    return 0;
}