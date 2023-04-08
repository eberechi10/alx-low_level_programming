#include "main.h"
#include <stdio.h>

/**
 * print_binary - function to print binary representation of a number
 * @n: is the number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int get;
	int m;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (get = n, m = 0; (get >>= 1) > 0; m++)
		;

	for (; m >= 0; m--)
	{
		if ((n >> m) & 1)
			printf("1");
		else
			printf("0");
	}
}
