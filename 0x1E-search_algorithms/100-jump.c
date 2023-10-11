#include "search_algos.h"

/**
 * jump_search - search value in an array using Jump search algorithm
 *
 * @array: the array
 * @size: the size
 *
 * @value: the value
 *
 * Return: the value searced
 */
int jump_search(int *array, size_t size, int value)
{
	int index, i, j, prev;

	if (array == NULL || size == 0)
		return (-1);

	m = (int)sqrt((double)size);
	j = 0;
	prev = index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		j++;
		prev = index;
		index = j * i;
	} while (index < (int)size && array[index] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, index);

	for (; prev <= index && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
