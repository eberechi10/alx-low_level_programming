#include "holberton.h"
#include <stdio.h>

/**
 * binary_to_uint - a funtion to convert a binary
 *
 * @b: it is a string
 *
 * Return: the coverted number or 0.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int count;
	unsigned int sun;
	int m;

	if (b == NULL)
		return (0);


	for (m = 0; b[m]; m++)
	{
		if (b[m] != '0' && b[m] != '1')
			return (0);
	}


	for (sun = 1, count = 0, m--; m >= 0; m--, sun *= 2)
	{
		if (b[m] == '1')
			count += 1;
	}

	return (count);
}
