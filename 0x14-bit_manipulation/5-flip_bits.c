#include "main.h"

/**
 * flip_bits - function that flip to get from one number to another.
 *
 * @n: is the first bit
 * @m: is the second bit.
 *
 * Return: the number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int old;
	unsigned long int new;
	unsigned int get, sun;

	get = 0;
	new = 1;
	old = n ^ m;
	for (sun = 0; sun < (sizeof(unsigned long int) * 8); sun++)
	{
		if (new == (old & new))
			get++;
		new <<= 1;
	}

	return (get);
}
