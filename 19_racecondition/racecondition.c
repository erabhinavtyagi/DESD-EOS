#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *incThread(void *);
void *decThread(void *);

int count =0;
int main()
{
    pthread_t inc,dec;
    pthread_create(&inc,NULL,incThread,NULL);
    pthread_create(&dec,NULL,decThread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    return 0;
}

void *incThread(void *arg)
{
    while(1)
    {
        count++;
        printf("Inc Thread : %d\n", count);
    }
}

void *decThread(void *arg)
{
    while(1)
    {
        count--;
        printf("Dec Thread : %d\n", count);
    }
}