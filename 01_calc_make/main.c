// Main function for Calc

#include <stdio.h>
#include "main.h"

int main()
{
	int a,b;

	printf ("Enter First Number: ");
	scanf ("%d",&a);
	printf ("Enter Second Number: ");
	scanf ("%d",&b);

	printf ("ADD: %d\n", add (a, b));
	printf ("SUB: %d\n", sub (a, b));
	printf ("MUL: %d\n", mul (a, b));
	printf ("DIV: %d\n", div (a, b));
	return 0;
}
