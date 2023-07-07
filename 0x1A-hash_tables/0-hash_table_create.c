#include "hash_tables.h"

/**
 * hash_table_create - a function that create hash table.
 *
 * @size: size of the hash
 *
 * Return: the new hash table if success, otherwise NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h_table;
	unsigned long int p;

	h_table = malloc(sizeof(hash_table_t));
	if (h_table == NULL)
		return (NULL);

	h_table->size = size;
	h_table->array = malloc(size * sizeof(hash_node_t *));

	if (h_table->array == NULL)
	{
		free(h_table);
		return (NULL);
	}

	for (p = 0; p < size; p++)
		h_table->array[p] = NULL;
	return (h_table);
}
