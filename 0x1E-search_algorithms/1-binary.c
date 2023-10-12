#include "search_algos.h"

/**
* binary_search - Binary search algorithm for array of integers.
 * @array: array
 *
 * @size: size of the array
 * @value: the value
 *
 * Return: the value, otherwise -1 if
*/

int binary_search(int *array, size_t size, int value)
{
	size_t idx, left, right, mid;

	if (array == NULL || size == 0)
		return (-1);
	left = 0;
	right = size - 1;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (idx = left; idx < right; idx++)
			printf("%d, ", array[idx]);
		printf("%d\n", array[idx]);
		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
