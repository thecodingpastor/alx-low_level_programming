#include "main.h"

/**
 * flip_bits - returns the number of bits you would need
 * to flip to get from one number to another.
 * to get from one number to another
 * @n: num 1
 * @m: num 2
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, numBits = 0;
	unsigned long int cur;
	unsigned long int x = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		cur = x >> i;
		if (cur & 1)
			numBits++;
	}
	return (numBits);
}
