#include "main.h"

/**
 * flip_bits - it is a function that flips a bit.
 *
 * @n: it is the first bit
 * @m: the second bit
 *
 * Return: the flipped bit
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int s, total;
	unsigned long int new, ex;

	total = 0;
	ex = n ^ m;

	for (s = 63; s >= 0; s--)

	{
	new = ex >> s;

	if (new & 1)
	total++;
	}


	return (total);

}
