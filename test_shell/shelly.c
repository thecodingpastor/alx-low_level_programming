#include "shelly.h"
char **ms_env;
/**
 * main - mimics simple shell
 * @argc: arg count
 * @envp: envp
 * Return: 0 or -1
 */
int main(int argc, char *envp[])
{
	char input[MAX_INPUT_SIZE];

	ms_env = envp;

	while (true)
	{
		prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
			printString("\n"), exit(2);
		input[_strlen(input) - 1] = '\0';

		if (_strlen(input) == 0)
			continue;
		execCommand(input, ms_env);
	}
	return (0);
}
