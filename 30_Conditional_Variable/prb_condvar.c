// Program to check the problems (i.e Occurance of Deadlock)
// if Conditional Variables is not used.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int event =0;
pthread_mutex_t event_mutex;

void *waitingThread(void *data)
{
printf("Waiting Thread : Grabbing the Mutex\n");
pthread_mutex_lock(&event_mutex);
printf("waiting Thread : Got the Mutex\n");
while (event !=1)
{
}
printf("Waiting Thread: Event is 1, I am Done");
// Actual code to do functionality.
pthread_mutex_unlock(&event_mutex);
}

void *fireThread(void *data)
{
printf("Fire Thread : Grabbing the Mutex\n");
pthread_mutex_lock(&event_mutex);
printf("Fire Thread : Got the Mutex\n");
event =1;
printf("Fire Thread : Event is 1, I am Done");
// Actual code to do functionality.
pthread_mutex_unlock(&event_mutex);
}

int main ()
{
pthread_t waiting_thread_id, fire_event_thread_id;

pthread_mutex_init(&event_mutex, NULL);

pthread_create(&waiting_thread_id,NULL,waitingThread,NULL);
pthread_create(&fire_event_thread_id,NULL,fireThread,NULL);
pthread_join(waiting_thread_id,NULL);
pthread_join(fire_event_thread_id,NULL); 

pthread_mutex_destroy(&event_mutex);
return 0;
}
