#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int
main(void)
{
	printf("gcd: %d\n", gcd(48,18));
	return EXIT_SUCCESS;
}

int
gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}
