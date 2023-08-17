#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by 'a separator'
 * @separator: arg 1
 * @n: arg 2
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list stringArgs;
	unsigned int i;

	va_start(stringArgs, n);

	if (separator == NULL)
		return;

	for (i = 0; i < n; i++)
	{
		char *value = va_arg(stringArgs, char*);

		if (value == NULL)
			printf("(nil)");
		else if (i == n - 1)
			printf("%s", value);
		else
			printf("%s%s", value, separator);
	}
	printf("\n");
}
