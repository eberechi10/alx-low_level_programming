#include "lists.h"

/**
 * print_dlistint - prints elements dlistint_t list.
 *
 * @h: dlistint_t head list.
 *
 * Return: list of elms.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t elms = 0;

	while (h)
	{
		elms++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (elms);
}
