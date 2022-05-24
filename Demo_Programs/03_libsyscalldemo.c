//Library and System Call Demo

#include <stdio.h>

int main()
{
printf("Hello World\n");
return 0;
}


// Run the executable file and check the STRACE. via command "strace ./filename"
// there is one system call "write(1, "Hello World\n", 12Hello World)"


