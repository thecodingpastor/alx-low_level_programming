#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: head of linked list
 * @index: position
 * Return: NULL or the node with the index
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *tmp = head;
	unsigned int i = 0;

	while (tmp && i < index)
		tmp = tmp->next, i++;
	if (!tmp)
		return (NULL);
	else
		return (tmp);
}
