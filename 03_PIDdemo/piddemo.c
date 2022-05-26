// Process Id Demo

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int
main ()
{
  pid_t pid;
  pid_t ppid;			// pid_t pid(void) ---> "get() & set()" for Opaque Datatype.

  pid = getpid ();
  ppid = getppid ();

  printf ("Process ID : %d\n", pid);
  printf ("Parent Process ID: %d\n", ppid);
  return 0;
}
