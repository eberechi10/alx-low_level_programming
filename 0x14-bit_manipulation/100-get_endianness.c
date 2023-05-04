#include "main.h"

/**
 * get_endianness - it is a function to get endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int sun = 1;
	char *gt;


	gt = (char *)&sun;

	return (*gt);
}
