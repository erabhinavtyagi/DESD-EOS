// To Receive Data of "stdio.h" from sender and print number of "s" in the file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>
#include <errno.h>

#define MAXSIZE 32000        //MAXIMUM DEFAULT QUEUE SIZE = 8Kb 

mqd_t mqd;

struct mq_attr attr;

int main(int argc, char const *argv[])
{
    int fd, count =0;
    unsigned int prio; 
    unsigned char buff[MAXSIZE]; 
        
    attr.mq_flags = 0;       
    attr.mq_maxmsg = 1;      
    attr.mq_msgsize = 8192;     
    attr.mq_curmsgs = 0;     
    
    mqd = mq_open("/stdio_mq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr);

    fd = open("/usr/include/stdio.h", O_RDONLY, S_IRUSR | S_IWUSR);

    ssize_t rec = mq_receive(mqd, buff, MAXSIZE, &prio);    
    
    if (rec == -1)
    {
        perror("Error in Receiving file.\n");
        printf("Error No.%d\n",errno);
        exit(EXIT_FAILURE);
    } 

    //while(read(mqd,(char *)&fd, sizeof(fd) != 0))
      for (int i =0; i<=strlen(buff); i++)
        {
            if (fd == 's')
            count++;
        }
        
    printf("\nS comes %d times in stdio.h \n", count);

    mq_close(mqd);
    return 0;
}
