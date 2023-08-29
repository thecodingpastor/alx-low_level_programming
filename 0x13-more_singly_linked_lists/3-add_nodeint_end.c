#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: head of linked list
 * @n: data of last item to be added
 * Return: address of new element or NULL
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *tmp, *ptr;

	ptr = malloc(sizeof(listint_t));
	tmp = *head;

	if (!ptr)
		return (NULL);
	ptr->n = n;
	ptr->next = NULL;

	if (*head == NULL)
	{
		*head = ptr;
		return (ptr);
	}

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ptr;

	return (ptr);
}
