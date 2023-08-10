#include <stdlib.h>
#include "main.h"

/**
 * _memset - fills memory
 * @s: arg 1
 * @b: arg 2
 * @n: arg 3
 *
 * Return: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _calloc -  allocates memory for an array, using malloc.
 *
 * @nmemb: arg 1
 * @size: arg 2
 *
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *var;

	if (nmemb == 0 || size == 0)
		return (NULL);
	var = malloc(nmemb * size);

	if (var == NULL)
		return (NULL);
	_memset(var, 0, size * nmemb);

	return (var);
}

