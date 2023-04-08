#include "main.h"
#include <stdio.h>

/**
 * get_bit - function to get the value of bit.
 *
 * @n: the bit to check number.
 * @index: it is the index of the bit = 0.
 *
 * Return: Value of bit at index, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int get;

	if (index > 64)
		return (-1);

	get = n >> index;

	return (get & 1);
}
