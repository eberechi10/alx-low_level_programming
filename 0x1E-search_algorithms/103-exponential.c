#include "search_algos.h"

/**
  * _binary_search - search for value in sorted array with binary search.
 *
  * @array: the array to search.
  * @left: the left sub array.

  * @right: the right sub array.
  * @value: the value to search.
  *
  * Return: the value, otherwise -1.
  */
int binary_search_h(int *array, size_t left, size_t right, int value)
{
	size_t idx;

	if (array == NULL)
		return (-1);
	while (right >= left)
	{
		printf("Searching in array: ");
		for (idx = left; idx < right; idx++)
			printf("%d, ", array[idx]);
		printf("%d\n", array[idx]);

		idx = left + (right - left) / 2;
		if (array[idx] == value)
			return (idx);

		if (array[idx] > value)
			right = idx - 1;
		else
			left = idx + 1;
	}

	return (-1);
}


/**
  * exponential_search - search value in sorted array with exponential search.
 *
  * @array: the array to search.
  * @size: the size.
 *
  * @value: value to search.
  *
  * Return: the value, otherwise -1.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t idx = 0, right;

	if (array == NULL)
		return (-1);
	if (array[0] != value)
	{
		for (idx = 1; idx < size && array[idx] <= value; idx = idx * 2)
			printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
	}
	right = idx < size ? idx : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", idx / 2, right);

	return (binary_search_h(array, idx / 2, right, value));
}
