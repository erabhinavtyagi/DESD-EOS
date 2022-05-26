#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{   int fd;
    fd = open ("desdlog.txt", O_WRONLY);
    //fd = open ("desdlog.txt", O_CREAT | O_WRONLY);    // Command to create the file(if not there) and open in write only mode.
   
    // if file does not open.
    if (-1 == fd)
    {
        perror("Error in Opening File.");    
        // printf will only print the msg but Perror will show the msg as well as system generated error (as per the error number)
    }
    
    // if file open normally.
    write (fd, "DESD\n", 5);
    close(fd);
    exit(EXIT_SUCCESS);
}