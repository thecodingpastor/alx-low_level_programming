#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 *
 * @str: arg
 *
 * Return: Always 0 (Success)
 */

char *_strdup(char *str)
{
	char *var;
	int i = 0;
	int j = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		i++;
	}

	var = malloc(sizeof(char) * (i + 1));

	if (var == NULL)
	{
		return (NULL);
	}

	for (j = 0; str[j]; j++)
	{
		var[j] = str[j];
	}
	return (var);
}
