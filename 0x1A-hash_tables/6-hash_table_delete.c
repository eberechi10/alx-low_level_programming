#include "hash_tables.h"

/**
 * hash_table_delete - a funct to delete a hash table.
 *
 * @ht: hash table
 *
 * Return: it returns void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	for (idx = 0; idx < ht->size; idx++)
	{
		while (ht->array[idx] != NULL)
		{
			next = ht->array[idx]->next;
			free(ht->array[idx]->key);

			free(ht->array[idx]->value);
			free(ht->array[idx]);

			ht->array[idx] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;

	ht->size = 0;
	free(ht);
}
