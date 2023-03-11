#include "main.h"

/**
 * _abs -compute absolute value og an integer.
 * @n: The Integer
 *
 * Return: Absolute  value of the integer.
 */
int _abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	else
	{
		return (n);
	}
}
