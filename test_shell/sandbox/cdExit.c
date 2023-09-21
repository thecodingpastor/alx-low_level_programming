#include "shelly.h"
/**
 * checkExitChangedir - handles "cd" and "exit"
 * @argc: arg counter
 * @argv: arg vectors
 */

void checkExitChangedir(int argc, char *argv[])
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit(_atoi(argv[1]));
		else
			exit(0);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		if (argc == 2)
		{
			if (chdir(argv[1]) == -1)
			{
				perror("cd");
			}
		}
	}
}
