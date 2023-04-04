#include "lists.h"

/**
 * delete_nodeint_at_index - delete the node at index of a linked list
 * @head: the head of linked list
 *
 * @index: the index of the node
 *
 * function that deletes the node at index of a linked list.
 * Return: if success 1 but if failed -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t new;
	listint_t *get;
	unsigned int m;

	m = 0;
	new = *head;

	if (*head == NULL)
		return (-1);

	while (m < index)
	{
		m++;
		get = new;
		if (new->next)
			new = new->next;
		else
			return (-1);
	}

	if (index == 0)
		*head = new->next;

	else if (new->next)
		get->next = new->next;
	else
		get->next = NULL;

	free(new);

	return (1);
}
