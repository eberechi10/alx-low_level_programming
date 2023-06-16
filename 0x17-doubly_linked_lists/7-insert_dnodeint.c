#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts node to dlistint_t list.
 *
 * @h: pointer to dlistint_t list head.
 * @idx: insert the new node.
 * @n: contains integer of new node.
 *
 * Return: success the new node, otherwise NULL.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *elm = *h, *new_n;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		elm = elm->next;
		if (elm == NULL)
			return (NULL);
	}

	if (elm->next == NULL)
		return (add_dnodeint_end(h, n));

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
		return (NULL);

	new_n->n = n;
	new_n->prev = elm;
	new_n->next = elm->next;
	elm->next->prev = new_n;
	elm->next = new_n;

	return (new_n);
}
