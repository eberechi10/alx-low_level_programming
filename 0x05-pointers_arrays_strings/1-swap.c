#include "main.h"

/**
 * swap_int - swaps int a and int b.
 *
 * @a: integer number.
 * @b: integer number.
 *
 * Return: O (Success)
 */
void swap_int(int *a, int *b)
{
	int s;

	s = *a;
	*a = *b;
	*b = s;
}
