// Zombie Process Demo

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t id;

    id = fork();
    {
        if (id == 0)
        {
            printf("Child Process ID = %d\t PPID = %d\n", getpid(), getppid());
        } 
        else if (id > 0)
        {
            printf("Parent Process ID = %d\t PPID = %d\n", getpid(), getppid());
            sleep(10);  
            // Parent on wait state and child process ends early and still shows an entry in process table.
            printf("Parent Process Completed.\n");
        }
        else
            perror("Failed Fork\n");
    }
}