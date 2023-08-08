#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings.
 * @s1: arg 1
 * @s2: arg 2
 *
 * Return: concat of arg 1 and arg 2
 */

char *str_concat(char *s1, char *s2)
{
	char *var;
	int i = 0;
	int j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	var = malloc(sizeof(char) * (i + j + 1));

	if (var == NULL)
		return (NULL);
	i = 0;
	j = 0;

	while (s1[i] != '\0')
	{
		var[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		var[i] = s2[j];
		i++;
		j++;
	}
	var[i] = '\0';
	return (var);
}
