#include "lists.h"

/**
 * listint_len - elements in a linked list.
 *
 * @h: head of the point
 * function to print elemrnts of linked listint_t.
 * Return: number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t element = 0;

	while (h != NULL)
	{
		h = h->next;
		element++;
	}

	return (element);
}
