#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: head of linked list
 * @idx: position to add new node
 * @n: data of the new node
 * Return: address of new node or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr;
	listint_t *tmp = *head;
	unsigned int i = 0;

	ptr = malloc(sizeof(listint_t));

	if (!head || !ptr)
		return (NULL);
	ptr->n = n;
	ptr->next = NULL;

	if (idx == 0)
	{
		ptr->next = *head;
		*head = ptr;
		return (ptr);
	}
	while (tmp && i < idx)
	{
		if (i == idx - 1)
		{
			ptr->next = tmp->next;
			tmp->next = ptr;
			return (ptr);
		}
		else
			tmp = tmp->next;
		i++;
	}
	return (NULL);
}
