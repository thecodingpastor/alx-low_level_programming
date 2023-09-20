#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define STR_LEN 300

void prompt(void);
void handleError(char *msg, bool exitApp);
int printString(char *str);
size_t splitToTokens(char *ms_cmd, char *argv[], char *ms_delim);
ssize_t execCommand(int argc, char *argv[], char *envp[]);
void redirection(int argc, char *argv[]);
void checkForFullPath(char *argv[], char *envp[]);
void lessThanMode(int argc, char *argv[], int i);
void greaterThanMode(int argc, char *argv[], int i);
void greater2Mode(int argc, char *argv[], int i);
void checkExitChangedir(int argc, char *argv[]);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *_strcat(char *dest, char *src);

int _strlen(char *s)
{
    int length = 0;

    while (*s != '\0')
        length++, s++;
    return (length);
}

int _strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int _atoi(char *str)
{
    int result = 0, sign = 1, i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == '-')
        sign = -1, i++;
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        result = result * 10 + (str[i] - '0'), i++;

    return (result * sign);
}

char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0')
        dest[i] = src[j], j++, i++;
    dest[i] = '\0';
    return (dest);
}

void prompt(void)
{
    printString("shelly_$ ");
}

int printString(char *str)
{
    return (write(STDOUT_FILENO, str, _strlen(str)));
}

void handleError(char *msg, bool exitApp)
{
    printString(msg);
    if (exitApp)
        exit(2);
}

size_t splitToTokens(char *ms_cmd, char *argv[], char *ms_delim)
{
    size_t ms_numTokens = 0;
    char *ms_token = strtok(ms_cmd, ms_delim);

    while (ms_token)
    {
        argv[ms_numTokens] = ms_token;
        ms_token = strtok(NULL, ms_delim);
        ms_numTokens++;
    }
    argv[ms_numTokens] = NULL;
    return (ms_numTokens);
}

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

ssize_t execCommand(int argc, char *argv[], char *envp[])
{
    int status;

    if (argc < 1)
    {
        return -1; // No command to execute
    }

    char *cmd = argv[0];
    checkExitChangedir(argc, argv);

    pid_t pid = fork();

    if (pid == 0)
    {
        redirection(argc, argv);

        if (strchr(cmd, '/') == NULL)
            checkForFullPath(argv, envp);
        else
        {
            execve(cmd, argv, envp);
            perror("execve");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        perror("fork");
    else
        waitpid(pid, &status, 0);

    return status;
}

void checkForFullPath(char *argv[], char *envp[])
{
    char *path = getenv("PATH");
    char path_copy[strlen(path) + 1];
    strcpy(path_copy, path);
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
}

void checkExitChangedir(int argc, char *argv[])
{
    if (_strcmp(argv[0], "cd") == 0 || _strcmp(argv[0], "exit") == 0)
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
        else
        {
            printString("In here\n");
            handleError("Usage: cd <directory>\n", 0);
        }
        return;
    }
}

int main(int argc, char *argv[], char *envp[])
{
    char *input = NULL;
    size_t input_len = 0;
    ssize_t read;

    while (true)
    {
        prompt();
        if ((read = getline(&input, &input_len, stdin)) == -1)
            free(input), exit(2);
        input[read - 1] = '\0';

        if (_strlen(input) == 0)
            continue;

        char *input_argv[64];
        size_t input_argc = splitToTokens(input, input_argv, " ");
        execCommand(input_argc, input_argv, envp);
    }

    free(input);
    return (0);
}
