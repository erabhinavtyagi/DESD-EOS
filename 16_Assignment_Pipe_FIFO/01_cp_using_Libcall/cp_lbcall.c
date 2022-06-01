// Write your own utility using Library Calls (fopen,fclose,fread,fwrite) to copy data 
// from one file to another file. Essentially you are implementing a copy utility.
// Fullfledged utility should support the following options:
// - Handling all the Errors.
// - cp srcfile destfile

#include <stdio.h>
#include <stdlib.h>         // For exit()
  
int main(int argc , char *argv[] )
{
    FILE *f_sender = NULL;
    FILE *f_receiver = NULL;

    char str;
  
    // Open one file for reading
    f_sender = fopen(argv[1], "r");     // argv[0] = name of program, argv[1] = First Argument i.e name of source file.
    if (f_sender == NULL)
    {    perror("Cannot open the destination file: ");
        //printf("Cannot open the source file: %s \n", argv[1]);
        exit(-1);
    }
    
   
    // Open another file for writing
    f_receiver = fopen(argv[2], "a");
    if (f_receiver == NULL)
    {   
        //printf("Cannot open the destination file: %s \n", argv[2]);
        perror("Cannot open the destination file: ");
        exit(-1);
    }
  
    // Read contents from file
    
    str = fgetc(f_sender);
    while (str != EOF)
    {
        fputc(str, f_receiver);
        str = fgetc(f_sender);
    }
  
    printf("\nContents copied to %s", argv[2]);
  
    fclose(f_sender);
    fclose(f_receiver);
    return 0;
}