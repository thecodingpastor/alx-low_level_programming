#include "shelly.h"
/**
 * checkForFullPath - checks if the path to a command exists
 * @argv: arg vector
 * @envp: envs
 */
void checkForFullPath(char *argv[], char *envp[])
{
	char *path = getenv("PATH"), *dir = NULL;
	char *path_copy = NULL;

	if (path == NULL)
	{
		printString("Error: PATH environment variable not found\n");
		return;
	}
	path_copy = (char *)malloc(_strlen(path) + 1);

	if (path_copy == NULL)
		printString("Error: Memory allocation failed\n"), exit(EXIT_FAILURE);
	_strcpy(path_copy, path), dir = _strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[256];

		_strcpy(full_path, dir), _strcat(full_path, "/");
		_strcat(full_path, argv[0]);
		if (access(full_path, X_OK) == 0)
		{
			if (_strcmp(argv[0], "cd") != 0 && _strcmp(argv[0], "cd ..") != 0)
				if (execve(full_path, argv, envp) == -1)
					printString("Error: "), perror(argv[0]);
			free(path_copy);
			return;
		}
		dir = _strtok(NULL, ":");
	}
	if (_strcmp(argv[0], "cd") != 0 && _strcmp(argv[0], "cd ..") != 0)
		printString(argv[0]), printString(": command not found\n");
	free(path_copy);
}
