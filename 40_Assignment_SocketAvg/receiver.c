// Take 10 integers from user and send it to receiver.
// Recever will do average and send back it to User1. USE SOCKET IPC

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <linux/in.h>
#include <arpa/inet.h>

int cfd;
float sum = 0;
float avg = 0;

struct sockaddr_in saddr;

int main(int argc, char const *argv[])
{
    int num, len;
    //int n;      
    cfd = socket(AF_INET, SOCK_STREAM, 0);

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.0.34");
    saddr.sin_port = htons(7880);

    len = sizeof(saddr);
    connect(cfd, (struct sockaddr *)&saddr, len);

    // n = sizeof(buff)/sizeof(int) ;
    // printf("Number of Elements are %d",n);

    for (int i = 0; i < 10; i++)
    {
        read(cfd, &num, sizeof(int));
        sum = sum + num;
    }
    avg = sum / 10;
    printf("Sum of 10 numbers is: %.2f\n", sum);
    printf("Average of 10 numbers is: %.2f\n", avg);

    write(cfd, &avg, sizeof(int));
    close(cfd);

    return 0;
}