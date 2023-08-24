#include "lists.h"

/**
 * print_list - prints the members of a linked list
 * @h: pointer to the list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *h)
{
    size_t numNodes = 0;

    while (h)
    {
        if (h->str == NULL)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        h = h->next;
        numNodes++;
    }

    return (numNodes);
}

