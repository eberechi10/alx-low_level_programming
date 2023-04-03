#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Function that will print all element.
 *
 * @h: is the head of node
 *
 * Return: the number of nodes
 *
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count += 1;
	}

	return (count);
}
