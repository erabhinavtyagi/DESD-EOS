#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid;

void *display(void *data)
{
    printf ("This is Thread.\n");
}

int main()
{
    printf("Before Thread Creation\n");
    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                     void *(*start_routine) (void *), void *arg);

    pthread_create(&tid, NULL, display, NULL);
//    sleep(1);                            // Delay given to check output of display()
    printf("After Thread Creation.\n");
    return 0;
}

