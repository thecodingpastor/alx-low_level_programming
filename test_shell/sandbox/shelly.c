#include "shelly.h"
/**
 * main - mimics simple shell
 * @argc: arg count
 * @argv: arg vector
 * @envp: envp
 * Return: 0 or -1
 */
int main(int argc, char *argv[], char *envp[])
{
	char *ms_linePointer, *input_argv[100];
	size_t ms_lineSize = 0, input_argc = 0;
	ssize_t read;
	int count = 0;

	(void) argc, (void) argv;
	while (true)
	{
		count++;
		prompt();
		read = _getline(&ms_linePointer, &ms_lineSize, stdin);

		if (read == -1)
			free(ms_linePointer), printString("\n"), exit(2);
		ms_linePointer[read - 1] = '\0';

		if (_strlen(ms_linePointer) == 0)
			continue;

		input_argc = splitToTokens(ms_linePointer, input_argv, " ");

		execCommand(input_argc, input_argv, envp, count);
	}
	free(ms_linePointer);
	return (0);
}
