#include "shelly.h"

/**
 * lessThanMode - handles "<" redirection
 * @argc: argc
 * @argv: argv
 * @i: int
 */
void lessThanMode(int argc, char *argv[], int i)
{
	int in_fd = -1;

	if (i < argc - 1)
	{
		in_fd = open(argv[i + 1], O_RDONLY);

		if (in_fd == -1)
			perror("open"), exit(EXIT_FAILURE);
		dup2(in_fd, STDIN_FILENO), close(in_fd), argv[i] = NULL;
	}
	else
		handleError("Missing input file.\n", 1);
}
/**
 * greaterThanMode - handles ">" redirection
 * @argc: argc
 * @argv: argv
 * @i: int
 */

void greaterThanMode(int argc, char *argv[], int i)
{
	int out_fd = -1;

	if (i < argc - 1)
	{
		out_fd = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

		if (out_fd == -1)
			perror("open"), exit(EXIT_FAILURE);
		dup2(out_fd, STDOUT_FILENO), close(out_fd), argv[i] = NULL;
	}
	else
		handleError("Missing output file.\n", 1);
}
/**
 * greater2Mode - handles "2>" redirection
 * @argc: argc
 * @argv: argv
 * @i: int
 */
void greater2Mode(int argc, char *argv[], int i)
{
	int out_fd = -1;

	if (i < argc - 1)
	{
		out_fd = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

		if (out_fd == -1)
			perror("open"), exit(EXIT_FAILURE);
		dup2(out_fd, STDERR_FILENO), close(out_fd), argv[i] = NULL;
	}
	else
		handleError("Missing output file.\n", 1);
}
