#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by separator
 * @separator: arg 1
 * @n: arg 2
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numList;
	unsigned int i;

	va_start(numList, n);

	if (separator == NULL)
		return;

	for (i = 0; i < n; i++)
	{
		int num = va_arg(numList, int);

		if (i == n - 1)
			printf("%d", num);
		else
			printf("%d%s", num, separator);
	}
	va_end(numList);

	printf("\n");
}
