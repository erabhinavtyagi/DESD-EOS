// Orphan Process Demo
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
            sleep(10);
            printf("Child Process Completed.\n");
        }
        else if (id > 0)
        {
            printf("Parent Process ID = %d\t PPID = %d\n", getpid(), getppid());
        }
        // Parent process ends early and child process gets a new Parent ID.
        else
            perror("Failed Fork\n");
    }
}