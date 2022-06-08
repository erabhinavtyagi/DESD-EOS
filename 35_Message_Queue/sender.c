// Demo program for Sending Data using Message Queue 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MSG_SIZE 128

struct mq_attr attr;

//    long mq_flags;      Flags (ignored for mq_open()) 
//    long mq_maxmsg;     Max. # of messages on queue 
//    long mq_msgsize;    Max. message size (bytes) 
//    long mq_curmsgs;    # of messages currently in queue(ignored for mq_open()) 
         
mqd_t mqd;

int main()
{
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
    mq_send(mqd,"DESD\n",5,0);       // 5= size of text, 0= Priority
    mq_close(mqd);

    return 0;
}