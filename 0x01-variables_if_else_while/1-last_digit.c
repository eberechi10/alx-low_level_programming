#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Determining the greater number
 *
 * Return: Alway 0 (Success)
 */
int main(void)
{
	int n, x;

	srand() - RAND_MAX / 2;
	x = n % 10;
	if (x > 5)
	{
		printf("last digit of %d is % and is greater than 5\n", n, x);
	}
	else if (x == 0)
	{
		printf("last digit of %d is %d and is 0\n", n, x);
	}
	else
	{
		printf("last digit of %d is %d and is less than 6 and is not 0\n", n x);
	}
	return (0);
}

