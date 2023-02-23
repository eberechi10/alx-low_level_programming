#include "main.h"

/**
 * print_diagonal - draw a diagonal line.
 * @n: number of times '\' is printed.
 *
 * Return: use _putchar only.
 */
void print_diagonal(void)
{
	int c, i;

	c = 0;

	while (n > 0)
	{
		i = c;
		while (i > 0)
		{
			_putchar(' ');
			i++;
		}
		_putchar('\\');
		_putchar('\n');
		c++;
		i--;
	}
	if (c < i)
		_putchar('\n');
}
