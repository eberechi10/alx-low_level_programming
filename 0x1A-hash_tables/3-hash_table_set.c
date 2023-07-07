#include "hash_tables.h"

void add_node_b(hash_node_t **head, hash_node_t *n_node);


/**
 * add_b_node - function to add new node from index.
 *
 * @head: index node.
 * @n_node: node to add.
 *
 * Return: Nothing to return.
 */
void add_b_node(hash_node_t **head, hash_node_t *n_node)
{
	if (*head == NULL)
		*head = n_node;

	n_node->next = *head;
	*head = n_node;
}


/**
 * hash_table_set - a function to set element to hash table.
 *
 * @ht: the hash table.
 * @key: the key to the hash.
 *
 * @value: the value.
 *
 * Return: 1 if success, otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t **ht_bot, *bt_ht, *n_ht;
	unsigned long int idx;
	char *v_dup;

	if (!ht || !key || !(*key) || !value)
		return (0);

	idx = key_index((unsigned char *)key, ht->size);
	ht_bot = &(ht->array[idx]);
	n_ht = ht->array[idx];

	v_dup = strdup(value);
	if (v_dup == NULL)
		return (0);

	while (n_ht)
	{
		if (strcmp(n_ht->key, key) == 0)
		{
			free(n_ht->value);
			n_ht->value = v_dup;
			return (1);
		}
		n_ht = n_ht->next;
	}

	bt_ht = malloc(sizeof(hash_node_t));
	if (bt_ht == NULL)
	{
		free(v_dup);
		return (0);
	}

	bt_ht->key = strdup(key);
	if (bt_ht->key == NULL)
	{
		free(v_dup);
		free(bt_ht);
		return (0);
	}

	bt_ht->value = v_dup;
	bt_ht->next = NULL;

	if (*ht_bot == NULL)
	{
		*ht_bot = bt_ht;
		return (1);
	}

	if (*ht_bot && strcmp((*ht_bot)->key, key) != 0)
		add_b_node(&(*ht_bot), bt_ht);

	return (1);
}
