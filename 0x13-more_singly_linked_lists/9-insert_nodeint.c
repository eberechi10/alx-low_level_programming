#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - insert a node at postion
 *
 * @head: it is the pointer to the node
 * @idx: the index
 *
 * @n: the new node to insert>
 *
 * Return: the address of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int m;
	listint_t *get, *sun;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
	get = *head;
		for (m = 0; m < idx - 1 && get != NULL; m++)
		{
			get = get->next;
		}
		if (get == NULL)
			return (NULL);
	}
	sun = malloc(sizeof(listint_t));
	if (sun == NULL)
		return (NULL);
	sun->n = n;
	if (idx == 0)
	{
		sun->next = *head;
		*head = sun;
		return (sun);
	}
	sun->next = get->next;
	get->next = sun;
	return (sun);
}
