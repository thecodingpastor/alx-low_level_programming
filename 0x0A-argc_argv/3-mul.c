#include <stdio.h>

/**
 * _atoi - changes the looking nums to nums
 * @str: string to be changed
 *
 * Return: A nnumber
 */

int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

/**
 * main - multiplies 2 nums
 *
 * @argc: arg
 * @argv: arg
 *
 * Return: Always 0(Success)
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", _atoi(argv[1]) * _atoi(argv[2]));
	return (0);
}
