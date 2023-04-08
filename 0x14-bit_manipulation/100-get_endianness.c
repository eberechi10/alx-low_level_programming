#include "main.h"

/**
 * get_endianness - a function to checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{

	int get;

	get = 1;
	if (*(char *)&get == 1)
		return (1);
	else
		return (0);
}
