#include  "main.h"

/**
 * handle_recursion - handles recursion
 * @iteration: arg
 * @n: arg 1
 *
 * Return: an int
 */

int handle_recursion(int n, int iteration)
{
	if (iteration * iteration > n)
		return (-1);
	if (iteration * iteration == n)
		return (iteration);
	return (handle_recursion(n, iteration + 1));
}

/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: arg
 *
 * Return: square root of n
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (handle_recursion(n, 0));
}
