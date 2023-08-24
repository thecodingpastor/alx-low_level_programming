#include "lists.h"
#include <string.h>
/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: arg 1
 * @str: arg 2
 * Return: address of new element or NULL
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newMem;
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
	newMem->next = *head;
	*head = newMem;

	return (*head);
}
