
#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint_end - add node at end of a listint_t list.
  *
  * @head: head of double pointer
  * @n: int add the list
  * Return: NULL if it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *sun;
	listint_t *moon;

	if (head == NULL)
		return (NULL);
	sun = malloc(sizeof(listint_t));

	if (sun == NULL)
		return (NULL);
	sun->n = n;
	sun->next = NULL;
	if (*head == NULL)
	{
	*head = sun;
		return (sun);
	}

	moon = *head;
	while (moon->next != NULL)
	{
		moon = moon->next;
	}
	moon->next = sun;
	return (sun);
}

/*This is a function that add a new node at the endset number*/
