#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 *
 * @min: arg 1
 * @max: arg 2
 *
 * Return: pointer
 */

int *array_range(int min, int max)
{
	int *var;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	var = malloc(sizeof(int) * size);

	if (var == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		var[i] = min++;

	return (var);
}
