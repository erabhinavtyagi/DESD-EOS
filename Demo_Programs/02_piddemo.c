// Process Id Demo

#include<sys/type.h>
#include<unistd.h>

int
main ()
{
  int pid_t pid, pid_t ppid;

  pid_tpid = getpid ();
  pid_tppid = getppid ();

  printf ("Process ID : %d\n", pid_tpid);
  printf ("Parent Process ID: %d\n", pid_tppid);
  return 0;
}
