#include "lists.h"

/**
 * sum_listint - the sum of the data (n) of a linked list.
 * @head: it is the pointer to the node
 *
 * function that returns the sum of all the data (n) of a linked list.
 *
 * Return: sum all the data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *get = head;


	while (get != NULL)
	{
		sum += get->n;
		get = get->next;
	}

	return (sum);
}
