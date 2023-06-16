#include "lists.h"

/**
 * add_dnodeint - adds node to the beginning linked list
 *
 * @head: Pointer of first node of list.
 * @n: contains detail of new node.
 *
 * Return: the new added node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_l;

	new_l = malloc(sizeof(dlistint_t));
	if (!new_l)
		return (NULL);

	new_l->n = n;
	new_l->next = *head;
	new_l->prev = NULL;

	if (*head)
		(*head)->prev = new_l;
	*head = new_l;

	return (new_l);
}
