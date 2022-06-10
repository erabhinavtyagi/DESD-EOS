// Assignment - IPC: Message Queue
// P2: Receive the structure from sender file and print it out

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <sys/types.h>
#include <unistd.h>

#define MSG_SIZE 1024

struct mq_attr attr;

typedef struct {
    pid_t pid, ppid;
}process;
   
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
   
    process p1;         //Structure Instance Created
   
    mqd = mq_open("/desdmq", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR, &attr);

    if(-1 == mqd)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
   
    int rec = mq_receive(mqd,(char *)&p1, MSG_SIZE, &priority);
    if (-1== rec)
    {
        perror("Message not Received.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Parent ID = %d\n", p1.ppid);
        printf("Child ID = %d\n", p1.pid);
        printf("Message Received Successfully.\n");
        mq_close(mqd);
    }
    
    return 0;
}