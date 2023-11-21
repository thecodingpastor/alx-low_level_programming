#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: current head
 * @n: data to be added
 * Return: address or NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	ptr = malloc(sizeof(listint_t));

	if (!ptr)
		return (NULL);
	ptr->next = *head;
	ptr->n = n;
	*head = ptr;

	return (ptr);
}
