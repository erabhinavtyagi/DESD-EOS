// Assignment : Counting Semaphore
// Memory Block Manager - Using the counting semaphore to manage the memory blocks.

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h> 

sem_t s;

void *processing(void *data)
{
    int n = *(int *)data;
        
    sem_wait(&s);
    printf("Thread[%d] acquired the resource.\n", n);
    sleep(1);
    sem_post(&s);
    printf("Thread[%d] finished\n", n);
}

int main()
{
    sem_init(&s, 0, 2);
    int num;
    printf("Enter the number of Threads: \n");
    scanf("%d",&num);

    pthread_t thread[num];

    for(int i=1;i<=num;i++)
    {
        pthread_create(&thread[i],NULL,processing,&i);
    }
    
    for(int i=1;i<=num;i++)
    {
        pthread_join(thread[i],NULL);
    }
return 0;
}