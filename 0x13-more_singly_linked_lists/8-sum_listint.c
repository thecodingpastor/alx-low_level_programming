#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n)
 * of a listint_t linked list.
 * @head: head of linked list
 * Return: sum of data
 */
int sum_listint(listint_t *head)
{
	listint_t *tmp = head;
	int sum = 0;

	while (tmp)
	{
		sum = sum + tmp->n;
		tmp = tmp->next;
	}
	return (sum);
}
