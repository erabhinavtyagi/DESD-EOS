// Fork Demo

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;                       
    printf("Before Fork : %d\n", getpid());
    id = fork();                              // Creates a child process and get its Process ID.
    printf("After fork : %d\n", getpid());    
    // It will execute two times - one for parent and one for child.
    return 0;
}
