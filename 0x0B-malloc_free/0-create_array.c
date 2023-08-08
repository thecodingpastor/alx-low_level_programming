#include <stdlib.h>
#include "main.h"


/**
 * create_array - 0-create_array.c
 *
 * @size: arg 1
 * @c: arg 2
 *
 * Return: a pointer or null
 */

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(size * sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}
	return  (str);
}
