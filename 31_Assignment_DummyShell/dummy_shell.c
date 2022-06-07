// Assignment - Create a Dummy Shell using exec().

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t id;
    unsigned char cmd[1024];
    printf("Before Exec()\n");
    id = fork();
    if(0==id)
    {
    printf("Child Process Activated.\n");
    printf("DUMMY SHELL # ");
    scanf("%s", cmd);
    execl("/bin/ls","/bin/ls", NULL);    
    }
    else
    {
        printf("Parent Process is Working.\n");
        // wait(NULL);
    }

    return 0;
}
