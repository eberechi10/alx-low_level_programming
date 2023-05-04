#include "main.h"

/**
 * binary_to_uint - it is a function that converts a binary to unsigned int.
 * @b: it is a pointer to the string.
 *
 * Return: converted binary or 0 if error.
 */
unsigned int binary_to_uint(const char *b)
{
	int n;
	unsigned int bin = 0;

	if (!b)
		return (0);

	for (n = 0; b[n] != '\0'; n++)
	{
		if (b[n] != '0' && b[n] != '1')
			return (0);

	}

	for (n = 0; b[n] != '\0'; n++)
	{
		bin <<= 1;

		if (b[n] == '1')
			bin += 1;
	}
	return (bin);

/* ALX project */
}
