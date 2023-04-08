#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * listint_t **_r - function to reallocates memory
 * @list: it is the linked list
 *
 * @size: size of the linked list
 * @new: the node to added
 *
 * Return: the list
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **current;
	size_t m;


	current = malloc(size * sizeof(listint_t *));
	if (current == NULL)
	{
		free(list);
		exit(98);
	}
	for (m = 0; m < size - 1; m++)
		current[m] = list[m];
	current[m] = new;
	free(list);
	return (current);
}


/**
 * print_listint_safe - the function to print a list.
 * @head: it is the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t m;
	size_t count = 0;
	const listint_t **sun = NULL;

	while (head != NULL)
	{
		for (m = 0; m < count; m++)
		{
			if (head == sun[m])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(sun);
				return (count);
			}
		}

		count++;
		sun = _r(sun, count, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	
	free(sun);
	return (current);
}
