#include <stdio.h>

/**
 * main - prints the number of args passed
 * @argc: number of args passed into main
 * @argv: array of string args
 *
 * Return: a number
 */

int main(int argc, char *argv[])
{
(void) argv;

	printf("%d\n", argc - 1);
	return (0);
}
