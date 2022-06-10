// Demo Program for Writing to Shared Memory 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

int *count = NULL;

int main()
{
    int shmfd;      // Shared Memory File Descriptor
    sem_t countsem;

    sem_open(&countsem, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP,1);
    shmfd = shm_open("/desdshm", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

    if (-1 == shmfd)
    {
        perror("shm_open");
        return EXIT_FAILURE;
    }

    ftruncate(shmfd, sizeof(int));
    count = (int *)mmap(NULL, sizeof(int), PROT_READ |PROT_WRITE, MAP_SHARED, shmfd, 0);
    // above "NULL" means that auto assignment of memory location by OS.

    while(1)
    {   
        sem_wait(&countsem);
        *count = *count + 1;
        sem_post(&countsem);
        sleep(1);
    } 
    
    sem_destroy(&countsem);
    return 0;
}