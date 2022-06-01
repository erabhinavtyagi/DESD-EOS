#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define Max_Buff_Size 5         // buffer size

int main()
{
    unsigned char buff[Max_Buff_Size];
    pid_t id;                  

    // File Descriptor '0' : To Read
    // File Descriptor '1' : To Write        
    int fd[2];          

    pipe(fd);               // Pipe Created for file descriptor BEFORE fork()
    id = fork();            // Child Process Created

    if (id == 0)
    {
        close (fd[1]);      // close write end
        printf("\nChild Process\n");
        
        read(fd[0],buff,sizeof(buff));
        printf("Child Data Received: %s \n", buff);
    }
    else 
    {
        close (fd[0]);      // close read end
        printf("Parent Process\n");
       
        write (fd[1], "DESD\n", 5);
        printf("Parent : Wrote Data\n");
    }
    return 0;
}