#include "lists.h"

/**
 * delete_nodeint_at_index - delete the node at index of a linked list
 * @head: the head of linked list
 *
 * @index: the index of the node
 *
 * function that deletes the node at index index of a linked list.
 *
 * Return: 1 if it succeed or -1 if it fail
 **/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int m;
	listint_t *get;
	listint_t *sun;

	if (head == NULL || *head == NULL)
		return (-1);


	if (index == 0)
	{
		sun = (*head)->next;
		free(*head);
		*head = sun;
		return (1);
	}

	get = *head;
	for (m = 0; m < index - 1; m++)
	{
		if (get->next == NULL)
			return (-1);
		get = get->next;
	}


	sun = get->next;
	get->next = sun->next;
	free(sun);
	return (1);
}
