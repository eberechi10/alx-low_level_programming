#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - it is a function that resets values of a bit to index
 * @n: the values
 * @index: the index
 * Return: 1 if success, otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int node;

	if (index > sizeof(n) * 8)
		return (-1);

	node = ~(1 << index);
	*n &= node;

	return (1);
}
