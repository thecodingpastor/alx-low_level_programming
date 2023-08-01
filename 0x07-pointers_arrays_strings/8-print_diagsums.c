#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: arg 1
 * @size: arg 2
 */

void print_diagsums(int *a, int size)
{
	int sumOne = 0;
	int sumTwo = 0;
	int b;

	for (b = 0; b < size; b++)
	{
		sumOne = sumOne + a[b * size + b];
	}

	for (b = size - 1; b >= 0; b--)
	{
		sumTwo = sumTwo + a[b * size + (size - b - 1)];
	}

	printf("%d, %d\n", sumOne, sumTwo);
}
