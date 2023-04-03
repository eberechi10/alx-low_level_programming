#include "lists.h"
#include <stdlib.h>

/**
  * add_nodeint - function to add a node at beginning of a list.
  *
  * @head: the head of pointer
  * @n: integer to add.
  * Return: NULL if it failed
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *sun;

	if (head == NULL)
		return (NULL);
	sun = malloc(sizeof(listint_t));
	if (sun == NULL)
		return (NULL);
	sun->n = n;
	sun->next = *head;
	*head = sun;
	return (sun);
}
