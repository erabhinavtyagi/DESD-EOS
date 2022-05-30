#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
int fdw;                            // File Descriptor "Write"
fdw =open("desdfifo", O_WRONLY);    // open fifo in Write-only mode.
write(fdw, "DESD\n", 5);            // writes up to 5 bytes from the buffer to the file referred by fdw.
close(fdw);                         // Close File Descriptor
return 0;
}