#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - A function that returns the sum of two a and b.
 * @a: arg 1.
 * @b: arg 2.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the difference b/w a and b.
 * @a: arg 1
 * @b: arg 2
 *
 * Return: The difference b/w a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Returns the product of a and b.
 * @a: arg 1.
 * @b: arg 2
 *
 * Return: The product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Returns the division of a and b.
 * @a: arg 1
 * @b: arg 2
 *
 * Return: The division of a and b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - Returns the modulus of a and b.
 * @a: arg 1.
 * @b: arg 2.
 *
 * Return: The modulus of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
