#include "hash_tables.h"

/**
 * hash_table_get - function to get value associated with key.
 *
 * @ht: hash table.
 * @key: the hash table key.
 *
 * Return: value of the key, otherwise NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *ht_bot;
	unsigned long int idx;

	if (!ht || !key || !(*key))
		return (NULL);

	ht_bot = ht->array[idx];

	while (ht_bot)
	{
		if (strcmp(ht_bot->key, key) == 0)
			return (ht_bot->value);

		ht_bot = ht_bot->next;
	}
	return (NULL);
}
