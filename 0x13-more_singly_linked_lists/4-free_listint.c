#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - a function that free a linked list.
 *
 * @head: is the head of a linked list.
 * print a function to free the list
 *
 * Return: void
 */

void free_listint(listint_t *head)
{
	listint_t *sun;


	while (head != NULL)
	{
		sun = head->next;
		free(head);
		head = sun;
	}
}
