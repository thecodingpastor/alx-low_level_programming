#include "shelly.h"
/**
 * redirection - handles redirection
 * @argc: arg counter
 * @argv: arg vector
 */
void redirection(int argc, char *argv[])
{
	int in_fd = -1, out_fd = -1, i;

	for (i = 0; i < argc; i++)
	{
		if (_strcmp(argv[i], "<") == 0)
			lessThanMode(argc, argv, i);
		else if (_strcmp(argv[i], ">") == 0)
			greaterThanMode(argc, argv, i);
		else if (_strcmp(argv[i], "2>") == 0)
			greater2Mode(argc, argv, i);
	}
}
