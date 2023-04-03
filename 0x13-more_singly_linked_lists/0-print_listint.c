#include "lists.h"
#include <stdio.h>

/**
 * print_listint - a function to print elements of a list.
 * this is a project on singly linked list.
 * @h: is head of the node
 *
 * Return: number of nodes
 *
 */

size_t print_listint(const listint_t *h)
{
	size_t element = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		element++;
	}
	return (element);
}

/* count the element in the list*/
