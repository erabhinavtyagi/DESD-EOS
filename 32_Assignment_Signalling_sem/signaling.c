// Assignment : Adding two Numbers given by User by using Signalling method 
// when both s1 = s2 = 1

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a,b,sum;
sem_t sem_i2p , sem_p2i; // i2p = Input to Processing Thread , p2i = Processing to Input Thread

void *inputThread (void *data)
{
while(1)
{
    sem_wait(&sem_p2i);
    scanf("%d", &a);
    scanf("%d", &b);
    sem_post(&sem_i2p);
}
}

void *processingThread (void *data)
{
while(1)
{
    sem_wait(&sem_i2p);
    sum = a + b;
    printf("Sum = %d\n", sum);
    sem_post(&sem_p2i);
}
}

int main()
{
    pthread_t input,processing;

    sem_init(&sem_i2p, 0 , 1);
    sem_init(&sem_p2i, 0 , 1);
    
    pthread_create(&input,NULL,inputThread,NULL);
    pthread_create(&processing,NULL,processingThread,NULL);
    pthread_join(input,NULL);
    pthread_join(processing,NULL);

    sem_destroy(&sem_i2p);
    sem_destroy(&sem_p2i);
        
    return 0;
}