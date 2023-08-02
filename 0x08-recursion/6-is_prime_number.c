#include "main.h"


/**
 * handle_prime_number - gets prime
 * @n: arg 1
 * @divisor: arg 2
 *
 * Return: returns a number
 */

int handle_prime_number(int n, int divisor)
{
	if (divisor == 1)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (handle_prime_number(n, divisor - 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * otherwise return 0.
 * @n: integer
 *
 * Return: 1 or 0
 */

int is_prime_number(int n)
{
	int highestDivisor = n / 2;

	if (n <= 1)
		return (0);
	return (handle_prime_number(n, highestDivisor));
}
