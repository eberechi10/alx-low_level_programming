#include "search_algos.h"

/**
* linear_search - a linear search algorithm on array integers.
 * @array: array to be searched
 * @size: size of the array
 * @value: the value
 *
 * Return:  value is located or failed -1.
*/

int linear_search(int *array, size_t size, int value)
{
	size_t idx;

	if (array == NULL)
		return (-1);
	for (idx = 0; idx < size; idx++)
	{
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
		{
			return (idx);
		}
	}
	return (-1);
}
