#include "shelly.h"

/**
 * printString - prints string to stdout
 * @str: string to be printed
 * Return: number of chars printed
 */
int printString(const char *str)
{
    return write(STDOUT_FILENO, str, strlen(str));
}
