#include "hash_tables.h"

/**
 * hash_djb2 - a function to implement djb2 algorithm
 *
 * @str: string hash value
 *
 * Return: if success hash value, otherwise NULL.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int p;

	hash = 5381;

	while ((p = *str++))
	{
		hash = ((hash << 5) + hash) + p; /* hash * 33 + c */
	}

	return (hash);
}
