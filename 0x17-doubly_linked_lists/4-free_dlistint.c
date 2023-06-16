#include "lists.h"

/**
 * free_dlistint - a function to free linked list
 *
 * @head: pointer to list first node.
 *
 * Return: it returns nothing.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *new = head;
	dlistint_t *old = head;

	if (!head)
		return;

	while (new->next)
	{
		new = new->next;
		free(old);
		old = new;
	}

	free(new);
}
