/* PTHREAD_MUTEX_ERRORCHECK
This type of mutex provides error checking. A thread attempting to relock this mutex
without first unlocking it will return with an error. A thread attempting to unlock
a mutex which another thread has locked will return with an error.
A thread attempting to unlock an unlocked mutex will return with an error. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define IN_MAIN     ""
#define IN_THREAD   "\t"
#define START_MAIN  printf(IN_MAIN "\n-- Main Start -- \n");
#define END_MAIN    printf(IN_MAIN "-- Main End -- \n\n");  \
                    exit(EXIT_SUCCESS);

#define ERROR_HANDLER(en, msg) \
                do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread_routine(void * arg)
{
    printf(IN_THREAD "-- Thread Start -- \n");
    int ret;

    pthread_mutex_lock(&mutex);
    printf(IN_THREAD " Thread acquire lock for first time \n");

    ret = pthread_mutex_lock(&mutex);
    if(ret)
    {
        switch(ret)
        {
            case EDEADLK:
                printf(IN_THREAD " A deadlock condition was detected \n");
                break;

            default:
                ERROR_HANDLER(ret, "pthread_mutex_lock");
        }
    }

    sleep(1);
    ret = pthread_mutex_unlock(&mutex);
    printf(IN_THREAD " Thread release lock first time -- %d \n", ret);

    sleep(1);
    ret = pthread_mutex_unlock(&mutex);
    printf(IN_THREAD " Thread release lock second time -- %d \n", ret);
    printf(IN_THREAD "-- Thread End --\n");
    pthread_exit(NULL);
}

int main(int argc, char ** argv)
{
    START_MAIN;
    pthread_t thread_id;
    pthread_mutexattr_t mutex_attr;
    int mutex_type, ret=0;

    pthread_mutexattr_init(&mutex_attr);
    ret = pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_ERRORCHECK);
    
    if(ret)
        ERROR_HANDLER(ret, "pthread_mutexattr_settype");

    pthread_mutex_init(&mutex, &mutex_attr);
    pthread_create(&thread_id, NULL, thread_routine, NULL);
    pthread_join(thread_id, NULL);
    END_MAIN;
}