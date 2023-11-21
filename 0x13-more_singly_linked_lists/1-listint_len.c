#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: pointer to linked list
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t numNodes = 0;

	while (h)
	{
		numNodes++;
		h = h->next;
	}

	return (numNodes);
}
