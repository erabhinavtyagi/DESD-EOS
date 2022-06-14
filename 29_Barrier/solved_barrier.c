// Demo Program using Barrier Synchronization (SOLUTION).
/* Synchronization" among all threads is maintained using Barrier and 
   now they are waiting for completion of the initialization of other threads 
   and are giving their output after that. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_barrier_t dev_init_barrier;

void *serialThread(void *data)
{
printf("Serial Thread : INIT Started\n");
sleep(7);                                   // Emulating serial port initialization
printf("Serial Thread : INIT Finished\n");
pthread_barrier_wait(&dev_init_barrier);    // Barrier wait

// Actual Code can be Written Here.
printf("Output from Serial Port.\n");
}

void *ethernetThread(void *data)
{
printf("Ethernet Thread : INIT Started\n");
sleep(10);                                  // Emulating Ethernet port initialization
printf("Ethernet Thread : INIT Finished\n");
pthread_barrier_wait(&dev_init_barrier);    // Barrier wait

// Actual Code can be Written Here.
printf("Output from Ethernet Port.\n");
}

void *lcdThread(void *data)
{
printf("LCD Thread : INIT Started\n");
sleep(10);                                  // Emulating Ethernet port initialization
printf("LCD Thread : INIT Finished\n");
pthread_barrier_wait(&dev_init_barrier);    // Barrier Wait

// Actual Code can be Written Here.
printf("Output from LCD Port.\n");
}

int main()
{
pthread_t serialThread_id, ethernetThread_id, lcdThread_id;

pthread_barrier_init(&dev_init_barrier, NULL, 3);   // 3 Barrier Initialize

pthread_create(&serialThread_id,NULL,serialThread,NULL);
pthread_create(&ethernetThread_id,NULL,ethernetThread,NULL);
pthread_create(&lcdThread_id,NULL,lcdThread,NULL);
pthread_join(serialThread_id,NULL);
pthread_join(ethernetThread_id,NULL);
pthread_join(lcdThread_id,NULL);                    

pthread_barrier_destroy(&dev_init_barrier);  // 3 Barrier Destroyed
return 0;
}