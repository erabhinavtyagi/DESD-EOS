// Assignment - IPC: Shared Memory
// P2: Receive the structure from sender file and print it out.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct pids
{
    pid_t ppid;
    pid_t pid;
} p1, *ptr;

int main()
{
    int shmfd; // Shared Memory File Descriptor

    shmfd = shm_open("/desdshm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

    if (-1 == shmfd)
    {
        perror("Error in Opening file.\n");
        return EXIT_FAILURE;
    }

    ftruncate(shmfd, sizeof(struct pids));

    ptr = (void *)mmap(NULL, sizeof(struct pids), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);

    printf("Parent ID = %d\n", ptr->ppid);
    printf("Child ID = %d\n\n", ptr->pid);
    // close(shmfd);
    return 0;
}