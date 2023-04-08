#include "main.h"
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
	unsigned int sun;
	int m;

	sun = 0;
	if (b == null)
		return (0);
	for (m = 0; b[m] != '\0'; m++)
	{
		if (b[m] != '0' && b[m] != '1')
			return (0);
	}
	for (m = 0; b[m] != '\0'; m++)
	{
		sun <<= 1;
		if (b[m] == '1')
			count += 1;
	}
	return (sun);
}