#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

#define Max_size 5                      // Buffer Size = 5

int main()
{
int fdr;                                // File Descriptor "Read"
unsigned char buff[Max_size];
fdr =open("desdfifo", O_RDONLY);        // open fifo in read only mode.
read(fdr, buff, 5);                     // Read upto 5bytes from fdr into Buffer
printf("Read Data : %s\n",buff);
close(fdr);                             // Close File Descriptor
return 0;
}