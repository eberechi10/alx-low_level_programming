#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - it frees a linked list
 * @head: is a pointer to the lists.
 * function that frees a listint_t list.
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *next;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		sun = (*head)->next;
		free(*head);
		sun = *head;
	}
}
