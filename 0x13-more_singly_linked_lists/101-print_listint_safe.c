#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - fuction to print a linked list.
 *
 * @head: is the head of list
 * 
 * go through the list only once.
 * Return: number of nodes in list. exit with status 98 if failed.
 *
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *get, *new;
	size_t sum;

	new = head;
	if (new == NULL)
		exit(98);


	sum = 0;
	while (new != NULL)
	{
		get = new;
		new = new->next;
		sum++;
		printf("[%p] %d\n", (void *)get, get->n);



		if (get < new)
		{
			printf("-> [%p] %d\n", (void *)new, new->n);
			break;
		}
	}


	return (sum);
}
