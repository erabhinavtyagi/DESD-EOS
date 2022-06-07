// Program to check the Solution (i.e Removal of Deadlock) using Conditional Variables.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int event =0;
pthread_mutex_t event_mutex;
pthread_cond_t event_cv;

void *waitingThread(void *data)
{
printf("Waiting Thread : Grabbing the Mutex\n");
pthread_mutex_lock(&event_mutex);
printf("waiting Thread : Got the Mutex\n");
while (event !=1)
{
    printf("Waiting Thread: Waiting with Cond_Var\n");
    pthread_cond_wait(&event_cv, &event_mutex);
    printf("Waiting Thread: Got the Cond_Var\n");
}
printf("Waiting Thread: Event is 1, I am Done\n");
// Actual code to do functionality.
pthread_mutex_unlock(&event_mutex);
printf("Waiting Thread: Released the Mutex\n");
}

void *fireThread(void *data)
{
printf("Fire Thread : Grabbing the Mutex\n");
pthread_mutex_lock(&event_mutex);
printf("Fire Thread : Got the Mutex\n");

event =1;
printf("Fire Thread : Event is 1, I am Done\n");
// Actual code to do functionality.
pthread_mutex_unlock(&event_mutex);
printf("Fire Thread: Released the Mutex\n");

pthread_cond_signal(&event_cv);
printf("Fire Thread: Signalled the Cond_var\n");
}

int main ()
{
pthread_t waiting_thread_id, fire_event_thread_id;

pthread_mutex_init(&event_mutex, NULL);
pthread_cond_init(&event_cv, NULL);

pthread_create(&waiting_thread_id,NULL,waitingThread,NULL);
pthread_create(&fire_event_thread_id,NULL,fireThread,NULL);
pthread_join(waiting_thread_id,NULL);
pthread_join(fire_event_thread_id,NULL); 

pthread_cond_destroy(&event_cv);
pthread_mutex_destroy(&event_mutex);
return 0;
}
