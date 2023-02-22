#include <stdio.h>

/**
 * pribt_to_98 - print all natural numbers.
 * @n: Input number.
 *
 * Return: no retun.
 */
int print_to_98(int n)
{
	if (n > 98)
	{
		for (n = 0; n > 98; n--)
		{
			printf("%d, ", n);
		}
	}
	else if (n < 98)
	{
		for (n = 0; n < 98; n++)
		{
			printf("%d, ", n);
		}
	}
	printf("%d\n", n);
}

		
