#include "lists.h"

/**
 * free_listint_safe - function to free the list while head is null
 *
 * @h: it is the head of list
 *
 * Return: size of the free list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *new;
	listint_t *get;
	size_t count = 0;


	new = *h;

	while (new != NULL)
	{
		node++;
		get = new;
		new = new->next;
		free(get);

		if (get < new)
			break;
	}

	*h = NULL;

	return (node);
}
