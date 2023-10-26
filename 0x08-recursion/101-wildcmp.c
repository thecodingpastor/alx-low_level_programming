#include "main.h"

/**
 *wildcmp - wild comparison
 *@one: arg 1
 *@two: arg 2
 *Return: integer
 */
int wildcmp(char *one, char *two)
{
	if (*one == '\0')
	{
		if (*two != '\0' && *two != '*')
			return (wildcmp(one, two + 1));
		return (*two == '\0');
	}
	else if (*two == '*')
		return (wildcmp(one + 1, two) || wildcmp(one, two + 1));
	else if (*one == *two)
		return (wildcmp(one + 1, two + 1))
	return (0);
}
