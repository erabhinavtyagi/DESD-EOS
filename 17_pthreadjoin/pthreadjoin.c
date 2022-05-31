#include <stdio.h>
#include <pthread.h>


pthread_t tid;

void *display (void *data)
{
    printf("This is a Thread.\n");
}

int main()
{
    printf("Before Thread.\n");
    pthread_create(&tid, NULL, display, NULL);
    printf("After Thread Creation.\n");
    pthread_join(tid, NULL);
    return 0;
}