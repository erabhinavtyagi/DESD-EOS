// Demo program for Sending Data using Message Queue 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MSG_SIZE 128

struct mq_attr attr;

mqd_t mqd;

int main()
{
    unsigned char buff[MSG_SIZE];          
    unsigned int priority;

    // Structure Defination
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;

    mqd = mq_open("/desdmq", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR, &attr);

    if(-1 == mqd)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
   
    mq_receive(mqd,buff,MSG_SIZE,&priority);
    printf("Message Received = %s\n", buff);
    mq_close(mqd);

    return 0;
}