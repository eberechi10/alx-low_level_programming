#include "hash_tables.h"


/**
 * shash_table_print_rev - print reverse keys and values of the shash table
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *elm;
	char *nod = "";

	if (ht == NULL)
		return;

	printf("{");
	nod = "";

	elm = ht->stail;

	while (elm != NULL)
	{
		printf("%s'%s': '%s'", nod, elm->key, elm->value);
		nod = ", ";

		elm = elm->sprev;
	}

	printf("}\n");
}


/**
 * shash_table_delete -function that delete shash table.
 *
 * @ht: shash table
 * Return: nothing to return.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int idx;
	shash_node_t *a;
	shash_node_t *b;

	if (ht == NULL)
		return;

	for (idx = 0; idx < ht->size; idx++)
	{
		a = ht->array[idx];
		while ((b = a) != NULL)
		{
			a = a->next;
			free(b->key);
			free(b->value);
			free(b);
		}
	}
	free(ht->array);
	free(ht);
}


/**
 * shash_table_create - function to create shash table.
 *
 * @size: the shash table size.
 *
 * Return: shash table if success, otherwise NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int idx;
	shash_table_t *sh_table;
	shash_node_t **array;

	array = malloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	sh_table = malloc(sizeof(shash_table_t));
	if (sh_table == NULL)
		return (NULL);

	for (idx = 0; idx < size; idx++)
		array[idx] = NULL;

	sh_table->array = array;
	sh_table->size = size;

	sh_table->shead = NULL;
	sh_table->stail = NULL;

	return (sh_table);
}



/**
 * add_idx_shash - function to addup node on the shash table.
 *
 * @ht: hash table
 * @curr: new node
 *
 * Return: return nothing.
 */
void add_idx_shash(shash_table_t *ht, shash_node_t *curr)
{
	shash_node_t *a, *b;
	int sum;

	a = b = ht->shead;

	while (a != NULL)
	{
		sum = strcmp(curr->key, a->key);
		if (sum == 0)
		{
			return;
		}
		else if (sum < 0)
		{
			curr->sprev = a->sprev;

			if (a->sprev)
				a->sprev->snext = curr;
			else
				ht->shead = curr;

			a->sprev = curr;
			curr->snext = a;

			return;
		}
		b = a;
		a = a->snext;
	}

	curr->sprev = b;
	curr->snext = NULL;

	if (ht->shead)
		b->snext = curr;
	else
		ht->shead = curr;

	ht->stail = curr;
}


/**
 * shash_table_set - function to set hash to given shash table.
 *
 * @ht: shash table
 * @key: the key.
 *
 * @value: the value.
 *
 * Return: success if 1, otherwise 0.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx_s;
	shash_node_t *node_n;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	idx_s = key_index((unsigned char *)key, ht->size);

	node_n = add_shash_d(&(ht->array[idx_s]), key, value);

	if (node_n == NULL)
		return (0);

	add_idx_shash(ht, node_n);

	return (1);
}


/**
 * shash_table_get - function to get value from key.
 *
 * @ht: the shash table.
 * @key: the key.
 *
 * Return: the value of the shash if success.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx_s;
	shash_node_t *elm;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	idx_s = key_index((unsigned char *)key, ht->size);

	elm = ht->array[idx_s];

	while (elm != NULL)
	{
		if (strcmp(elm->key, key) == 0)
			return (elm->value);

		elm = elm->next;
	}

	return (NULL);
}


/**
 * add_shash_d - function to addup node to beginning shash.
 *
 * @t: shash head.
 * @key: the shash key.
 *
 * @value: the value.
 *
 * Return: the result of the add node.
 */
shash_node_t *add_shash_d(shash_node_t **t, const char *key, const char *value)
{
	shash_node_t *elm;

	elm = *t;

	while (elm != NULL)
	{
		if (strcmp(key, elm->key) == 0)
		{
			free(elm->value);
			elm->value = strdup(value);

			return (elm);
		}
		elm = elm->next;
	}

	elm = malloc(sizeof(shash_node_t));

	if (elm == NULL)
		return (NULL);

	elm->key = strdup(key);
	elm->value = strdup(value);

	elm->next = *t;

	*t = elm;

	return (elm);
}


/**
 * shash_table_print - function that print keys and values of shash table.
 *
 * @ht: shash table.
 *
 * Return: nothing to return.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *elm;
	char *nod;

	if (ht == NULL)
		return;

	printf("{");
	nod = "";

	elm = ht->shead;

	while (elm != NULL)
	{
		printf("%s'%s': '%s'", nod, elm->key, elm->value);
		nod = ", ";

		elm = elm->snext;
	}

	printf("}\n");
}

