#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * followed by a new line
 * @a: the array to be printed from
 * @n: number of terms to be printed
 */

void print_array(int *a, int n)
{
	int i;

	i = 0;

	for (i = 1; i <= n; i++)
	{
		if (i == n)
		{
			printf("%d", a[i]);
		} else
		{
			printf("%d, ", a[i]);
		}
	}
	printf("\n");
}
