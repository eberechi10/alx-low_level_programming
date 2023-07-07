#include "hash_tables.h"

/**
 * hash_table_print - function that print keys and values of hash table.
 *
 * @ht: hash table.
 *
 * Return: nothing to return.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *elm;
	char *tab;

	if (ht == NULL)
		return;

	printf("{");
	tab = "";

	for (idx = 0; idx < ht->size; idx++)
	{
		elm = ht->array[idx];

		while (elm != NULL)
		{
			printf("%s'%s': '%s'", tab, elm->key, elm->value);
			tab = ", ";

			elm = elm->next;
		}
	}
	printf("}\n");
}
