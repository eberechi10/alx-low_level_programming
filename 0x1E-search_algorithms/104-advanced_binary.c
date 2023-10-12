#include "search_algos.h"

/**
 * recur_search - search for value in array with Binary search
 *
 * @array: the array
 * @size: the size
 * @value: the value to search
 * Return: the value, otherwise -1.
 */
int recur_search(int *array, size_t size, int value)
{
	size_t a_half = size / 2;
	size_t idx;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array");
	for (idx = 0; idx < size; idx++)
		printf("%s %d", (idx == 0) ? ":" : ",", array[idx]);
	printf("\n");

	if (a_half && size % 2 == 0)
		a_half--;
	if (value == array[a_half])
	{
		if (a_half > 0)
			return (recur_search(array, a_half + 1, value));
		return ((int)a_half);
	}
	if (value < array[a_half])
		return (recur_search(array, a_half + 1, value));
	a_half++;
	return (recur_search(array + a_half, size - a_half, value) + a_half);
}


/**
 * advanced_binary - uses recur_search output
 *
 * @array: the array
 *
 * @size: the size of array
 * @value: the value to search
 *
 * Return: the index, otherwise -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = recur_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);
	return (index);
}
