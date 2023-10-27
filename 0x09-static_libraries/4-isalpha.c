#include "main.h"

/**
 * _isalpha - checks if a char is an alphabet
 * @c: char to be checked
 * Return: 1 if true, else return false
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}

	return (0);
}
