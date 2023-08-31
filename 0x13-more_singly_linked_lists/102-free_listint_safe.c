#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: head to be freed
 * Return: size of list freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i = 0;
	int difference;
	listint_t *tmp;

	if (!h || !*h)
		return (0);

	for (i = 0; *h != NULL; i++)
	{
		difference = *h - (*h)->next;
		if (difference > 0)
		{
			tmp = (*h)->next;
			free(*h), *h = tmp;
		}
		else
		{
			free(*h), *h = NULL;
			break;
		}
	}
	*h = NULL;

	return (i);
}
