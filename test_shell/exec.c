#include "shelly.h"
/**
 * execCommand - executes a command
 * @ms_cmd: command passed
 * @envp: envp
 *Return: a number
 */
ssize_t execCommand(char *ms_cmd, char *envp[])
{
	char *argv[64];
	int argc = splitToTokens(ms_cmd, argv), status;

	checkExitChangedir(argc, argv);

	pid_t pid = fork();

	if (pid  == 0)
	{
		redirection(argc, argv);

		if (strchr(argv[0], '/') == NULL)
			checkForFullPath(argv, envp);
		else
		{
			execve(argv[0], argv, envp);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, &status, 0);
}
