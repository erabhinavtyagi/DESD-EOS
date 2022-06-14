// Assignment - IPC: Shared Memory
//     P1: Declare your own structure => {pid, ppid}
//     P1: Tranfer structure to another process P2

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
        perror("Error in Opening File\n");
        return EXIT_FAILURE;
    }

    ftruncate(shmfd, sizeof(p1));
    ptr = (void *)mmap(NULL, sizeof(struct pids), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);

    // above "NULL" means that auto assignment of memory location by OS.

    printf("%d\n", p1.ppid = getppid());
    printf("%d\n", p1.pid = getpid());

    *ptr = p1;
    // close(shmfd);

    return 0;
}