#include "main.h"

/**
 * more_numbers - ptrint 10 times the numbers from 0 - 14.
 *
 * Return: you can use _putchar 3 times.
 */
void more_numbers(void)
{
	int c, i;

	c = 0;
	while (c < 10)
	{
		i = 0;
		while (i < 15)
		{
			if (i > 9)

				_putchar(i / 10 + '0'0);
			i++;
		}
		c++;
		_putchar('\n');
	}
}
