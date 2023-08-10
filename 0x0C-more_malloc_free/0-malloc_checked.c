#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - a function that allocates memory using malloc
 *
 * @b: arg
 * Return: a void pointer
 */

void *malloc_checked(unsigned int b)
{
	void *var;

	var = malloc(b);

	if (var == NULL)
	{
		exit (98);
	}
	return (var);
}
