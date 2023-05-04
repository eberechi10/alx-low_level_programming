#include "main.h"

/**
 * set_bit - it is a function to sets the value of a bit.
 * @n: it is the number
 * @index: the index of the bit.
 *
 * Return: 1 if success, otherwise -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int pet;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	pet = 1 << index;
	*n = *n | pet;

	return (1);
/* A project to get the index */

}
