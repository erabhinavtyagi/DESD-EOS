#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before Exec()\n");
    execl("/bin/ls", "/bin/ls", NULL);
    printf("After Exec()\n");
    return 0;
}
