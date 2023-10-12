#include "search_algos.h"

/**
 * interpolation_search - for value in a sorted array using interpolation
 *
 * @array: the array to search
 * @size: size of the array
 *
 * @value: the value
 *
 * Return: the value, otherwise -1.
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t a_low = 0;
	size_t a_high = size - 1;
	size_t a_pos;


	if (!array)
		return (-1);

	while ((array[a_high] != array[a_low]) &&
	       (value >= array[a_low]) && (value <= array[a_high]))
	{
		a_pos = a_low + (((double)(a_high - a_low) / (array[a_high] - array[a_low]))
			    * (value - array[a_low]));
		printf("Value checked array[%lu] = [%d]\n", a_pos, array[a_pos]);
		if (array[a_pos] < value)
			a_low = a_pos + 1;
		else if (value < array[a_pos])
			a_high = a_pos - 1;
		else
			return (a_pos);
	}
	if (value == array[a_low])
	{
		printf("Value checked array[%lu] = [%d]\n", a_low, array[a_low]);
		return (a_low);
	}
	a_pos = a_low + (((double)(a_high - a_low) / (array[a_high] - array[a_low]))
		     * (value - array[a_low]));
	printf("Value checked array[%lu] is out of range\n", a_pos);
	return (-1);
}
