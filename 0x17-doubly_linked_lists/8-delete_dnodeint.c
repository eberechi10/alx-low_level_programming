#include "lists.h"

/**
 * delete_dnodeint_at_index - a function to delete node of dlistint_t
 *
 * @head: pointer dlistint_t head.
 * @index: node index to be deleted
 *
 * Return: success 1, otherwise -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *elm = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (elm == NULL)
			return (-1);
		elm = elm->next;
	}

	if (elm == *head)
	{
		*head = elm->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		elm->prev->next = elm->next;
		if (elm->next != NULL)
			elm->next->prev = elm->prev;
	}

	free(elm);

	return (1);
}
