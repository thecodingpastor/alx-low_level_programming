#include "shelly.h"

/**
 * printString - prints string
 * @str: string to be printed
 * Return: number of strings printed
 */

int printString(const char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}
