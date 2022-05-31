#include <stdio.h>
#include <pthread.h>

pthread_t tid;
pthread_attr_t attr;

void *display(void *data)
{
    printf("This is Thread\n");
}

int main()
{
    pthread_attr_init(&attr);       // Default Attributes
    // Set Attributes - Thread Detach states
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    printf("Before Thread Creation\n");
    pthread_create(&tid, &attr, display, NULL);
    pthread_attr_destroy(&attr);
    printf("After Thread Creation.\n");
    pthread_join(tid, NULL);
    return 0;
}