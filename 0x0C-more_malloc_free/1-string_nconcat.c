#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat -  function that concatenates two strings.
 *
 * @s1: arg 1
 * @s2: arg 2
 * @n: arg 3
 * Return: a pointer
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, firstLen = 0, secLen = 0;
	char *var;

	while (s1 && s1[firstLen])
	{
		firstLen++;
	}
	while (s2 && s2[secLen])
		secLen++;

	if (n < secLen)
	{
		var = malloc(sizeof(char) * (firstLen + n + 1));
	} else
	{
		var = malloc(sizeof(char) * (firstLen + secLen + 1));
	}
	if (var == NULL)
		return (NULL);
	while (i < firstLen)
	{
		var[i] = s1[i];
		i++;
	}
	while (n < secLen && i < (firstLen + secLen))
	{
		var[i] = s2[j];
		i++, j++;
	}
	var[i] = '\0';

	return (var);
}
