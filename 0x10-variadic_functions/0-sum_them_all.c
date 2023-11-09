#include <stdarg.h>

/**
 * sum_them_all -  returns the sum of all its parameters.
 * @n: number of items to be summed
 *
 * Return: sum of items
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list numList;
	int sum = 0;
	unsigned int i;

	va_start(numList, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
	{
		int num = va_arg(numList, int);

		sum += num;
	}
	return (sum);
}
