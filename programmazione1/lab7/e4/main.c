#include <stdio.h>
#include <stdlib.h>


int sum(int a, int b);

int
main(void)
{
	printf("sum: %d\n", sum(2, 3));
	return EXIT_SUCCESS;
}

int
sum(int a, int b)
{
	if(!a)
		return b;
	return sum(a-1, b+1);
}
