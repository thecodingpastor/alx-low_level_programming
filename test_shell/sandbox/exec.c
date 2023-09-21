#include "shelly.h"
/**
 * execCommand - executes a command
 * @argc: arg count
 * @argv: aarg vector
 * @envp: envp
 * @count: count
 *Return: a number
 */
ssize_t execCommand(int argc, char *argv[], char *envp[], int count)
{
	int status;
	char *cmd = NULL;
	pid_t pid;

	if (argc < 1)
		return (-1);
	cmd = argv[0];

	if (_strcmp(argv[0], "cd") == 0 || _strcmp(argv[0], "exit") == 0)
		checkExitChangedir(argc, argv);
	pid = fork();

	if (pid == 0)
	{
		redirection(argc, argv);
		if (_strchr(cmd, '/') == NULL)
		{
			checkForFullPath(argv, envp);
		}
		else
		{
			if (execve(cmd, argv, envp) == -1)
			{
				printNum(count), printString(": otside found\n"), printString(cmd);
				perror("execve"), exit(EXIT_FAILURE);
			}
			else
			{
				printString(": otside found\n");
			}
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, &status, 0);
	return (status);
}
