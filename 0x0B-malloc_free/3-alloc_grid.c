#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 *
 * @width: arg 1
 * @height: arg 2
 *
 * Return: pointer
 */

int **alloc_grid(int width, int height)
{
	int **var;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	var = malloc(sizeof(int *) * height);

	if (var == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		var[i] = malloc(sizeof(int) * width);

		if (var[i] == NULL)
		{
			for (; i >= 0; i--)
				free(var[i]);
			free(var);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			var[i][j] = 0;
	}
	return (var);
}
