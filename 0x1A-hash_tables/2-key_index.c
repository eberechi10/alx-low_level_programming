#include "hash_tables.h"

/**
 * key_index - generates the index of a key.
 *
 * @key:  the key index.
 * @size: the hash tables size.
 *
 * Return: the index if success, otherwise Null.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);

	return (hash_djb2(key) % size);
}
