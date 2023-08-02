#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to calculate the length of
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * handle_palindrome - checks the characters recursively for palindrome
 * @s: string to check
 * @i: iterator
 * @len: length of the string
 *
 * Return: 1 if palindrome, 0 if not
 */
int handle_palindrome(char *s, int i, int len)
{
	if (*(s + i) != *(s + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (handle_palindrome(s, i + 1, len - 1));
}


/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not.
 * @s: arg
 *
 * Return: an int
 */

int is_palindrome(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (handle_palindrome(s, 0, _strlen_recursion(s)));
}
