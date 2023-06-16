#include "lists.h"

/**
 * sum_dlistint - a function to sums all data in dlistint_t list.
 *
 * @head: dlistint_t list head
 *
 * Return: sum of data.
 */
int sum_dlistint(dlistint_t *head)
{
	int counter;

	counter = 0;

	while (head)
	{
		counter += head->n;
		head = head->next;
	}

	return (counter);
}
