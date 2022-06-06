// Problem without using Semaphores (Signalling method)

#include<stdio.h>
#include<pthread.h>

int a,b,sum;

void *inputThread (void *data)
{
while(1)
{
    scanf("%d", &a);
    scanf("%d", &b);
}
}

void *processingThread (void *data)
{
while(1)
{
    sum = a + b;
    printf("Sum = %d\n", sum);
}
}

int main()
{
    pthread_t input,processing;
    
    pthread_create(&input,NULL,inputThread,NULL);
    pthread_create(&processing,NULL,processingThread,NULL);
    pthread_join(input,NULL);
    pthread_join(processing,NULL);
        
    return 0;
}