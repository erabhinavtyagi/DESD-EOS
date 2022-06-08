// Assignment - Create a Dummy Shell using exec().

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t id;
    unsigned char cmd[1024];
    
    printf("DUMMY SHELL # ");
    scanf("%s", cmd);
    
    id = fork();
    if(0==id)
    {
    printf("Child Process Activated.\n");
    execl(cmd,cmd, NULL);    
    }
    else
    {
        printf("Parent Process is Working.\n");
        wait(NULL);
    }

    return 0;
}
