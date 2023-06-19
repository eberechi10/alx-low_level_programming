#include "main.h"

/**
 * _islower - check if a character is lowercase.
 * @c: the character to be checkef
 * Return: 1 if its lowercas, 0 otherwise.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
