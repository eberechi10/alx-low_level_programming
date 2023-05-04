#include"main.h"

/**
 * get_bit - it is a function that gets the index of a bit.
 * @n: the number of th bit.
 * @index: the index of the bit
 *
 * Return: if success bit, otherwise -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int node;
	unsigned long int sap;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	node = 1 << index;
	sap = n & node;

	if (sap == node)
		return (1);

	return (0);
}
