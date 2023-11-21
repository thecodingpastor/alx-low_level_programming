#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: head of linked list
 * Return: 0 or head node's data
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	tmp = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = tmp;

	return (n);
}
