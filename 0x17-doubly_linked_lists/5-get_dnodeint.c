#include "lists.h"

/**
 * get_dnodeint_at_index - gets a node in dlistint_t.
 *
 * @head: the dlistint_t list head.
 * @index: node to get.
 *
 * Return: if success the node, otherwise NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *new = head;
	unsigned int x;

	if (!head)
		return (NULL);

	for (x = 0; new; x++)
	{
		if (x == index)
			return (new);

		new = new->next;
	}

	return (NULL);
}
