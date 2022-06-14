// Take 10 integers from user and send it to receiver.
// Recever will do average and send back it to User1. USE SOCKET IPC

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <linux/in.h>
//#include <arpa/inet.h>

int sfd, cfd;           //sfd : Server File Descriptor , cfd: Client File Descriptor
int len;

struct sockaddr_in saddr, caddr;

unsigned int buff[10];

void input(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("\nEnter Number[%d]: ",i);
        scanf("%d", &buff[i]);
      //  write(cfd, &buff[i], sizeof(int));            // Working Correctly Here Also.
    }
}

int main(int argc, char const *argv[])
{
    float avg =0;
    
    sfd = socket(AF_INET, SOCK_STREAM, 0);                  // Socket Created

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.0.34");
    saddr.sin_port = htons(7880);

    len =sizeof(saddr);  
    //len =sizeof(struct sockaddr_in);  
                                       

    if (bind(sfd, (struct sockaddr *)&saddr, len) == -1)    // Bind IP:Port
    {
        perror("Error in Binding\n");
        exit(EXIT_FAILURE);
    }

    if (listen(sfd, 15) == -1)                         // Number of client requests to file descriptor
    {
        perror("Error in Listening\n");
        exit(EXIT_FAILURE);
    }

    cfd = accept(sfd, (struct sockaddr *)&caddr, &len);     // Accept request from User2

    if (cfd == -1)
    {
        perror("Error in Accept\n");
        exit(EXIT_FAILURE);
    }

    input();
    
    write(cfd, &buff, sizeof(buff));            // Send to User2
  
    read(cfd, &avg, sizeof(float));               // Receive from User2
    printf("Average of 10 numbers is: %.2f\n", avg);

    close(cfd);
    close(sfd);

    return 0;
}