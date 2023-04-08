#include "main.h"

/**
 * clear_bit - a functoion to set the value of a bit to 0.
 *
 * @n: is the pointer of the bit.
 * @index: it is the index of the bit = 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int get;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	get = ~(1 << index);
	*n = *n & get;

	return (1);
}
