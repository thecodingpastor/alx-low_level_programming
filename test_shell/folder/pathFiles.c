#include "shelly.h"
/**
 * checkExitChangedir - checks if "exit" or "cd" is entered
 * and handles them accordingly
 * @argc: number of tokens
 * @argv: arg vectors
 */
void checkExitChangedir(int argc, char *argv[])
{
	if (argc > 0)
	{
		if (strcmp(argv[0], "exit") == 0)
			exit(0);
		else if (strcmp(argv[0], "cd") == 0)
		{
			if (argc == 2)
				if (chdir(argv[1]) == -1)
					perror("cd");
			else
				fprintf(stderr, "Usage: cd <directory>\n");
			return;
		}
	}
}
