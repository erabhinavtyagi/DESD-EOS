// Demo Program Without using Barrier Synchronization (PROBLEM).
/* Here problem is that there is "No Synchronization" among all threads
   and they are not waiting for completion of the initialization of other threads 
   and are giving their output after respective sleep() duration. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *serialThread(void *data)
{
printf("Serial Thread : INIT Started\n");
sleep(7);       // Emulating serial port initialization
printf("Serial Thread : INIT Finished\n");
// Actual Code can be Written Here.
printf("Output from Serial Port.\n");
}

void *ethernetThread(void *data)
{
printf("Ethernet Thread : INIT Started\n");
sleep(10);       // Emulating Ethernet port initialization
printf("Ethernet Thread : INIT Finished\n");
// Actual Code can be Written Here.
printf("Output from Ethernet Port.\n");
}

void *lcdThread(void *data)
{
printf("LCD Thread : INIT Started\n");
sleep(10);       // Emulating Ethernet port initialization
printf("LCD Thread : INIT Finished\n");
// Actual Code can be Written Here.
printf("Output from LCD Port.\n");
}

int main()
{
pthread_t serialThread_id, ethernetThread_id, lcdThread_id;

pthread_create(&serialThread_id,NULL,serialThread,NULL);
pthread_create(&ethernetThread_id,NULL,ethernetThread,NULL);
pthread_create(&lcdThread_id,NULL,lcdThread,NULL);
pthread_join(serialThread_id,NULL);
pthread_join(ethernetThread_id,NULL);
pthread_join(lcdThread_id,NULL);

return 0;
}