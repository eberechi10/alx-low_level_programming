#include "lists.h"

/**
 * add_dnodeint_end - adds node to end of dlistint_t list.
 *
 * @head: a pointer to dlistint_t list head.
 * @n: contains new node.
 *
 * Return: success the new node, otherwise NULL.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_l, *cu;

	new_l = malloc(sizeof(dlistint_t));
	if (new_l == NULL)
		return (NULL);

	new_l->n = n;
	new_l->next = NULL;

	if (*head == NULL)
	{
		new_l->prev = NULL;
		*head = new_l;
		return (new_l);
	}

	cu = *head;
	while (cu->next != NULL)
		cu = cu->next;
	cu->next = new_l;
	new_l->prev = cu;

	return (new_l);
}
