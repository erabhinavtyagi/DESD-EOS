// Write your own utility using Library Calls (fopen,fclose,fread,fwrite) to copy data 
// from one file to another file. Essentially you are implementing a copy utility.
// Fullfledged utility should support the following options:
// - Handling all the Errors.
// - cp srcfile destfile

#include <stdio.h>
#include <stdlib.h>         // For exit()

#define Max_Buff 8192       // Buffer size = 8byte

int main(int argc , char *argv[] )
{
    FILE *f_sender = NULL;
    FILE *f_receiver = NULL;

    size_t in, out;
   // char buf[BUFSIZ];       //Default size declared in stdio.h
    char buf[Max_Buff];
    int bufsize;
  
    // Open one file for reading
    f_sender = fopen(argv[1], "r");     // argv[0] = name of program, argv[1] = First Argument i.e name of source file.
    if (f_sender == NULL)
    {    perror("Cannot open the destination file: ");
        //printf("Cannot open the source file: %s \n", argv[1]);
        exit(1);
    }
    
    // Open another file for writing
    f_receiver = fopen(argv[2], "w");
    if (f_receiver == NULL)
    {   
        //printf("Cannot open the destination file: %s \n", argv[2]);
        perror("Cannot open the destination file: ");
        exit(1);
    }
    
    bufsize = atoi(argv[1]);
   // if (bufsize > BUFSIZ) 
    if(bufsize > Max_Buff)
    {
        perror("Limit exceeds the Buffer size.");
        exit(1);
    }
    // Read contents from file
    while (1) 
    {
        in = fread(buf, 1, /*BUFSIZ*/Max_Buff, f_sender);
        if (0 == in) break;
        out = fwrite(buf, 1, in, f_receiver);
        if (0 == out) break;
    }
  
    printf("\nContents copied to %s", argv[2]);
  
    fclose(f_sender);
    fclose(f_receiver);
    return 0;
}