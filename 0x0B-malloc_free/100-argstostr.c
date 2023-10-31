#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of your program.
 *
 * @ac: arg 1
 * @av: arg 2
 *
 * Return: pointer
 */

char *argstostr(int ac, char **av)
{
	int i, j, k = 0, l = 0;
	char *var;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			l++;
	}
	l += ac;

	var = malloc(sizeof(char) * (l + 1));

	if (var == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			var[k] = av[i][j];
			k++;
		}

		if (var[k] == '\0')
		{
			var[k++] = '\n';
		}
	}
	return (var);
}
