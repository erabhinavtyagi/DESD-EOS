// Assignment 2: Create a file, Read From it, Print it on screen, close the file.

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{   int fd;
    char file_read[20];
    fd = open ("file1.txt", O_RDONLY);
    //fd = open ("desdlog.txt", O_CREAT | O_RDWR);    // Command to create the file(if not there) and open in write only mode.
   
    // if file does not open.
    if (-1 == fd)
    {
        perror("Error in Opening File.");    
        // printf will only print the msg but Perror will show the msg as well as system generated error (as per the error number)
    }
    
    // if file open normally.

    while(read (fd, file_read, 20) != 0)
    {
     printf ("%s", file_read);   
    }
    
    close(fd);
    exit(EXIT_SUCCESS);
}