// Write your own utility using System Calls (open,close,read,write) to copy data 
// from one file to another file. Essentially you are implementing a copy utility.
// Fullfledged utility should support the following options:
// - Handling all the Errors.
// - cp srcfile destfile

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_BUFF 2048               // Buffer Size 2KB

int main (int argc , char *argv[])
{
int src, dest, n;                                 // File Descriptors 
ssize_t read_in, write_out;
char buf[MAX_BUFF];

// Open Source File
src = open(argv[1], O_RDONLY);
if (src < 0)        
{
   perror("Error opening source file");
   return(-1);
}
else 
// Read the source file.
{
   read_in = read(src, buf, sizeof( buf));
}

// Create the Destination file if it is not there.
dest = creat(argv[2], O_CREAT);
if (dest < 0)
{
   perror("Error creating destination file");
   return(-1);
}          
   
// Read The Source File.
read_in = read(src, buf, sizeof( buf));        // return the number of bytes read into read_in
while( read_in != 0) 
  {
   if (read_in < 0)                             // Print error if nothing to read.
   {
      perror("Error reading source file");
      return(-1);
   }
   else
   {
   write_out=0;
   // DO write to the destination file till write bytes equals to read bytes.
   do {              
       n = write(dest, &buf[write_out], read_in-write_out);   // return the number of bytes left to write into write_out
       if (n < 0)                               
         {
          perror("Error writing destination file");   
          return(-1);
         }
         write_out += n;
      } 
    while (write_out < read_in);
   }
    close(src);         //Close Source file
    close(dest);        //Close Destination file
   }

   return 0;
}
