// C program to find number of Zombie processes this system can handle.

#include<stdio.h>
#include<unistd.h>
  
int main()
{
    int count = 0;
    while (fork() > 0)
    {
        count++;
        printf("%d\n", count);
    }
}

//Output for my PC is "10154". It depends upon system configuration.