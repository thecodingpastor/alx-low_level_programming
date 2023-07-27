#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers.
 * @a: int a
 * @b: int b
 */

void reverse_array(int *a, int n)
{
	int i, j;

	for (i = 0; i < n--; i++)
	{
		j = a[i];
		a[i] = a[n];
		a[n] = j;
	}
}
