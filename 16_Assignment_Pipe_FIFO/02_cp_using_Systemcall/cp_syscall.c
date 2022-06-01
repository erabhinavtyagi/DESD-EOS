// Write your own utility using System Calls (open,close,read,write) to copy data 
// from one file to another file. Essentially you are implementing a copy utility.
// Fullfledged utility should support the following options:
// - Handling all the Errors.
// - cp srcfile destfile

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFF 1024

int main (int argc, char** argv)
{
int src, dest, num_read, num_write, n;
char buf[MAX_BUFF];

if ((src=open(argv[1], O_RDONLY)) < 0) 
{
   perror("Error opening source file");
   exit(1);
}

if ((dest = creat(argv[2], 0666)) < 0) 
{
   perror("Error creating destination file");
   exit(2);
} 

 while((num_read = read(src, buf, sizeof( buf))) != 0) 
  {
   if (num_read < 0) 
    {
       perror("Error reading source file");
       exit(3);
    }
     num_write=0;

    do {
       if ((n=write(dest, &buf[num_write], num_read-num_write)) < 0) 
         {
          perror("Error writing destination file");
          exit(4);
          }
         num_write += n;
       } 
    while (num_write < num_read);
  }
    close(src);
    close(dest);
}
