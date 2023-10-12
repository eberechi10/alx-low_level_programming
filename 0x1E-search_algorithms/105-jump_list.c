#include "search_algos.h"
#include <math.h>

/**
 * jump_list - search for value in array jump search
 * @list: the list
 * @size: the size of array
 * @value: the value to search
 *
 * Return: the index of the array
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, j, i;
	listint_t *old;

	if (list == NULL || size == 0)
		return (NULL);

	i = (size_t)sqrt((double)size);
	index = 0;
	j = 0;

	do {
		old = list;
		j++;
		index = j * i;

		while (list->next && list->index < index)
			list = list->next;
		if (list->next == NULL && index != list->index)
			index = list->index;
		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);
	} while (index < size && list->next && list->n < value);
	printf("Value found between indexes ");

	printf("[%d] and [%d]\n", (int)old->index, (int)list->index);

	for (; old && old->index <= list->index; old = old->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)old->index, old->n);
		if (old->n == value)
			return (old);
	}
	return (NULL);
}
