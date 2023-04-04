#include "lists.h"

/**
 * get_nodeint_at_index - a function to print the nth node of linked list.
 *
 * @head: it is the pointer to the node
 * @index: it is the index of the node
 *
 * Return: Null
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int m;

	if (head == NULL)
	return (NULL);
	for (m = 0; m < index; m++)
	{
		head = head->next;

		if (head == NULL)
			return (NULL);
	}

	return (head);

}
