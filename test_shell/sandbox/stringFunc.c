#include "shelly.h"
/**
 * _strlen - returns the length of a string.
 * @s: string to be processed
 * Return: Always returns an integer
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
		length++, s++;
	return (length);
}
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: an integer
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/**
 * _strtok - tokenizes strings like strtok
 * @str: string to tokenize
 * @delim: delimeter
 * Return: pointer to the first token
 */
char *_strtok(char **str, char delim)
{
	if (*str == NULL)
		return (NULL);

	char *start = *str, *end = *str;

	while (*end != '\0' && *end != delim)
		end++;
	if (*end == '\0')
		*str = NULL;
	else
		*end = '\0';
		*str = end++;
	return (start);
}
/**
 * _atoi - changes the looking nums to nums
 * @str: string to be changed
 *
 * Return: A number
 */
int _atoi(char *str)
{
	int result = 0, sign = 1, i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sign = -1, i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i] - '0'), i++;

	return (result * sign);
}
