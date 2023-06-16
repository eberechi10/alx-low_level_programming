#include "lists.h"
#include <stdio.h>


/**
 * dlistint_len - finds the lenght of linked list
 *
 * @h: the pointer of the list
 *
 * Return: the lenght of nodes.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t lenght = 0;
	const dlistint_t *cu = h;

	while (cu != NULL)
	{
		cu = cu->next;
		lenght++;
	}

	return (lenght);
}
