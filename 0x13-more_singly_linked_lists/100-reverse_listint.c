#include "lists.h"

/**
 * reverse_listint - it reverses a linked list.
 * @head: it is the pointer to the node
 *
 * You can only use two variables in your function.
 * You can use only 1 loop.
 *
 * Return: first node of the reversed list pointer.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *get;
	listint_t *new;

	if (head == NULL || *head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);

	get = NULL;
	while (*head != NULL)
	{
		new = (*head)->next;
		(*head)->next = get;
		get = *head;
		*head = new;
	}

	*head = get;
	return (*head);
}
