// Assignment - IPC: Message Queue
//     P1: Declare your own structure => {pid, ppid}
//     P1: Tranfer structure to another process P2

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
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;

    process p1;
    p1.pid = getpid();
    p1.ppid = getppid();

    mqd = mq_open("/desdmq", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR, &attr);

    if(-1 == mqd)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
   
    int sender = mq_send(mqd,(const char *)&p1, sizeof(p1),0);
    if(-1 == sender)
    {
        perror("Message not sent.\n");
        exit(EXIT_FAILURE);
    } else
    {
        printf("Parent ID: %d\n",p1.ppid);
        printf("Child ID: %d\n",p1.pid);
        printf("Message Sent Successfully.\n");
    }      
    mq_close(mqd);

    return 0;
}