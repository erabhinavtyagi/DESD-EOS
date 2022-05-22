// Section -demo


#include <stdio.h>
#include <stdlib.h>
int a;
int b = 10;

int add (int, int);

int
main ()
{
  int result = 0;
  int *p = NULL;
  p = (int *) malloc (sizeof (int));

  printf("Sum = %d\n",add (10, 20));
  return 0;

}

int
add (int a, int b)
{
  return (a + b);
}
