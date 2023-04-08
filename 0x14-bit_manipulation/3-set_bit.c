#include "main.h"

/**
 * set_bit - function to set the value of a bit to 1.
 *
 * @index: is the index of the bit = 0.
 * @n: it is the pointer.
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int sun;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	sun = 1 << index;
	*n = *n | sun;

	return (1);
}
