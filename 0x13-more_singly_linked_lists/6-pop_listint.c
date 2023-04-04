#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - a function to deletes the list head
 * @head: is the pointer
 *
 * Return: zero
 */
int pop_listint(listint_t **head)
{
	listint_t *sun;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	sun = *head;
	*head = sun->next;

	n = sun->n;
	free(sun);

	return (n);
}
