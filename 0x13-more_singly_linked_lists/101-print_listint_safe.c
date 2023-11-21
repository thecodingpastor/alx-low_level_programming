#include "lists.h"
/**
 * count - Counts the number of unique nodes
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Else - the number of unique nodes in the list.
 */
size_t count(const listint_t *head)
{
	const listint_t *one, *two;
	size_t numNodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	one = head->next;
	two = (head->next)->next;

	while (two)
	{
		if (one == two)
		{
			one = head;

			while (one != two)
			{
				numNodes++;
				one = one->next, two = two->next;
			}
			one = one->next;
			while (one != two)
			{
				numNodes++;
				one = one->next;
			}
			return (numNodes);
		}
		one = one->next;
		two = (two->next)->next;
	}
	return (0);
}
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head of linked list
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t numNodes = count(head);
	size_t i = 0;

	if (numNodes == 0)
		for (; head != NULL; numNodes++)
			printf("[%p] %d\n",
				(void *)head, head->n), head = head->next;
	else
	{
		for (i = 0; i < numNodes; i++)
			printf("[%p] %d\n",
				(void *)head, head->n), head = head->next;
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (numNodes);
}
