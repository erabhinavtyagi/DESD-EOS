// Fork Demo2

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;

    id = fork(); // Creates a child process and get its Process ID.

    if (id == 0)
    {
        printf("Child Process ID = %d\n", getpid());
    }
    else if (id > 0)
    {
        printf("Parent Process ID = %d\n", getppid());
    }
    else
    perror("Failed Fork");

    return 0;
}
