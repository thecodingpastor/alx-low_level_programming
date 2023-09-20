#include "shelly.h"
/**
 * checkForFullPath - checks if the path to a command exists
 * @argv: arg vector
 * @envp: envs
 */
void checkForFullPath(char *argv[], char *envp[])
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[256];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, argv[0]);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, argv, envp);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
}
