#include "main.h"

/**
 * _pow - it is a function to compute base raised power.
 * @base: it is the base
 * @power: it is the power
 *
 * Return: the base value.
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned int n;
	unsigned long int bin = 1;

	for (n = 1; n <= power; n++)

		bin *= base;

	return (bin);
}

/**
 * print_binary - it is a function to prints binary.
 * @n: It is the number
 *
 * Return: void if success or else.
 */
void print_binary(unsigned long int n)
{
	unsigned long int node;
	unsigned long int sap;
	char red = 0;


	node = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (node != 0)
	{
		sap = n & node;

		if (sap == node)
		{
			red = 1;
			_putchar('1');
		}

		else if (red == 1 || node == 1)
		{
			_putchar('0');
		}

		node >>= 1;
	}
}
