#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list.
 * @head:  head of linked list
 * @index: index of deltetion
 * Return: 1 or -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *cur = NULL;
	listint_t *tmp = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	while (i < index - 1)
	{
		if (tmp == NULL || tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	cur = tmp->next;
	tmp->next = cur->next;
	free(cur);
	return (1);
}
