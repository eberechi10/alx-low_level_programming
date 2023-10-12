#include "search_algos.h"

/**
 * linear_skip - search for value in skip list
 *
 * @list: the head of skip list
 * @value: the value to search
 *
 * Return: the value is located, otherwise NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *elm = NULL, *end = NULL;

	if (!list)
		return (NULL);
	elm = list;
	while (elm && elm->express && elm->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       elm->express->index, elm->express->n);
		elm = elm->express;
	}
	end = elm;
	while (end && end->next != end->express)
		end = end->next;
	if (elm->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       elm->express->index, elm->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       elm->index, elm->express->index);
	}
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
		       elm->index, end->index);
	while (elm != end && elm->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       elm->index, elm->n);
		elm = elm->next;
	}
	printf("Value checked at index [%lu] = [%i]\n",
	       elm->index, elm->n);
	if (elm == end)
		return (NULL);
	return (elm);
}
