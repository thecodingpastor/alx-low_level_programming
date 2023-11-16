#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: arg 1
 * @str: arg 2
 * Return: address or NULL
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newMem;
	list_t *tmp = *head;
	unsigned int len = 0;

	while (str[len])
	{
		len++;
	}

	newMem = malloc(sizeof(list_t));
	if (!newMem)
		return (NULL);
	newMem->str = strdup(str);
	newMem->len = len;
	newMem->next = NULL;

	if (*head == NULL)
	{
		*head = newMem;
		return (newMem);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newMem;
	return (newMem);
}
