#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define INITIAL_BUFFER_SIZE 128
#define MAX_PATH_LENGTH 4096

void prompt(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void handleError(char *msg, bool exitApp);
int printString(char *str);
size_t splitToTokens(char *ms_cmd, char *argv[], char *ms_delim);
// ssize_t execCommand(int argc, char *argv[], char *envp[], int count, bool *ctrlCFlag);
ssize_t execCommand(int argc, char *argv[], char *envp[], int count, bool *ctrlCFlag, int input_fd, int output_fd);
void redirection(int argc, char *argv[]);
void checkForFullPath(char *argv[], char *envp[]);
void lessThanMode(int argc, char *argv[], int i);
void greaterThanMode(int argc, char *argv[], int i);
void greater2Mode(int argc, char *argv[], int i);
void checkExitChangedir(int argc, char *argv[]);
void handleCtrlCSignal(int sig, bool *ctrlCFlag);
int printNum(int num);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);

/**
 * _strlen - returns the length of a string.
 * @s: string to be processed
 * Return: Always returns an integer
 */
int _strlen(char *s)
{
    int length = 0;

    while (*s != '\0')
        length++, s++;
    return (length);
}
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: an integer
 */
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
/**
 * _atoi - mimics standard atoi
 * @str: string to work on
 * Return: integer
 */
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
/**
 * _strcat - appends the src string to the dest string
 * overwriting the terminating null byte (\0)
 * at the end of dest, and then adds a terminating null byte
 * @dest: firsdt string to concat
 * @src: second striong to concat
 *
 * Return: a pointer to the resulting string dest
 */
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

/**
 * _strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: destination
 * @src: source
 * Return: Returns a char
 */

char *_strcpy(char *dest, char *src)
{
    int i = -1;

    do
    {
        i++;
        dest[i] = src[i];
    } while (src[i] != '\0');

    return (dest);
}

/**
 * _strchr - locates a character in a string.
 * @s: arg 1
 * @c: arg 2
 *
 * Return: a pointer to the first occurrence of the character
 */

char *_strchr(char *str, char c)
{
    int a = 0;

    for (; str[a] >= '\0'; a++)
    {
        if (str[a] == c)
        {
            return (&str[a]);
        }
    }
    return (0);
}
/**
 * _strtok - tokenizes a string
 * @str: string to be tokenized
 * @c: delim
 * Return: a pointer to the tokens
 */
/**
 * _strtok - tokenizes a string
 * @str: string to be tokenized
 * @c: delim
 * Return: a pointer to the tokens
 */
char *_strtok(char *str, char *c)
{
    if (!c)
        return (NULL);
    static char *ms_buff;

    if (str)
        ms_buff = str;
    else if (!ms_buff || !*ms_buff)
        return (NULL);

    char *ms_token = ms_buff;
    int i = 0, len = _strlen(c);

    while (*ms_buff && i != len)
    {
        i = 0;

        while (*ms_buff && *ms_buff != *c)
            ms_buff++;
        while (ms_buff[i] == c[i] && i < len)
            i += 1;
        if (i == len)
            *ms_buff = 0, ms_buff += len;
        else
            ms_buff++;
    }
    return (ms_token);
}

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        // errno = EINVAL; // Invalid arguments
        return -1;
    }

    if (*lineptr == NULL || *n == 0)
    {
        // If the lineptr is not initialized, allocate initial memory
        *n = INITIAL_BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
        {
            return -1; // Memory allocation failed
        }
    }

    int c;
    size_t i = 0;

    while ((c = fgetc(stream)) != EOF)
    {
        if (i >= (*n - 1))
        {
            // Resize the buffer if needed
            size_t new_size = *n * 2;
            char *new_ptr = (char *)realloc(*lineptr, new_size);
            if (new_ptr == NULL)
            {
                return -1; // Memory allocation failed
            }
            *lineptr = new_ptr;
            *n = new_size;
        }

        (*lineptr)[i++] = (char)c;

        if (c == '\n')
        {
            (*lineptr)[i] = '\0'; // Null-terminate the string
            return i;             // Number of characters read (including newline)
        }
    }

    if (i == 0)
    {
        return -1; // No data read
    }

    (*lineptr)[i] = '\0'; // Null-terminate the string
    return i;             // Number of characters read (without newline)
}

// void handleCtrlCSignal(int sig, bool *ctrlCFlag)
// {
//     if (ctrlCPressed)
//     {
//         printString("\nCTRL+C pressed again. Going...\n");
//         exit(0);
//     }
//     else
//     {
//         // Set the flag to indicate CTRL+C was pressed
//         ctrlCPressed = true;
//         printString("\nCTRL+C pressed. Press again to exit.\n");
//     }
// }

void handleCtrlCSignal(int sig, bool *ctrlCFlag)
{
    if (*ctrlCFlag)
    {
        printString("\nCTRL+C pressed again. Going...\n");
        exit(0);
    }
    else
    {
        *ctrlCFlag = true;
        printString("\nCTRL+C pressed. Press again to exit.\n");
    }
}

void prompt(void)
{
    printString("shelly_$ ");
}

int printString(char *str)
{
    return (write(STDOUT_FILENO, str, _strlen(str)));
}

int printNum(int num)
{
    int digits = 0;

    if (num < 0)
    {
        putchar('-');
        num = -num;
        digits++;
    }

    if (num == 0)
    {
        putchar('0');
        digits++;
    }
    else
    {
        int temp = num;
        char buffer[20]; // Buffer to hold the digit characters
        int index = 0;

        while (temp > 0)
        {
            int digit = temp % 10;
            buffer[index] = '0' + digit;
            temp /= 10;
            index++;
            digits++;
        }

        // Print the digits in reverse order from the buffer
        for (int i = index - 1; i >= 0; i--)
        {
            putchar(buffer[i]);
        }
    }
    return digits;
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
    char *ms_token = _strtok(ms_cmd, ms_delim);

    while (ms_token)
    {
        argv[ms_numTokens] = ms_token;
        ms_token = _strtok(NULL, ms_delim);
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

ssize_t execCommand(int argc, char *argv[], char *envp[], int count, bool *ctrlCFlag, int input_fd, int output_fd)
{
    int status;

    // ... (signal handling)
    // signal(SIGINT, handleCtrlCSignal);
    // handleCtrlCSignal(SIGINT, ctrlCFlag);

    if (argc < 1)
    {
        return -1;
    }

    char *cmd = argv[0];
    if (_strcmp(argv[0], "cd") == 0 || _strcmp(argv[0], "exit") == 0)
        checkExitChangedir(argc, argv);

    pid_t pid = fork();

    if (pid == 0)
    {
        // Redirect input/output to pipes if needed
        if (input_fd != STDIN_FILENO)
        {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd != STDOUT_FILENO)
        {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        redirection(argc, argv);

        if (_strchr(cmd, '/') == NULL)
        {
            checkForFullPath(argv, envp);
        }
        else
        {
            if (execve(cmd, argv, envp) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        perror("fork");
    else
        waitpid(pid, &status, 0);

    return status;
}

// // ssize_t execCommand(int argc, char *argv[], char *envp[], int count)
// ssize_t execCommand(int argc, char *argv[], char *envp[], int count, bool *ctrlCFlag)
// {
//     int status;

//     signal(SIGINT, handleCtrlCSignal);
//     handleCtrlCSignal(SIGINT, ctrlCFlag);
//     if (argc < 1)
//     {
//         return -1;
//     }

//     char *cmd = argv[0];
//     if (_strcmp(argv[0], "cd") == 0 || _strcmp(argv[0], "exit") == 0)
//         checkExitChangedir(argc, argv);

//     pid_t pid = fork();

//     if (pid == 0)
//     {
//         redirection(argc, argv);

//         if (_strchr(cmd, '/') == NULL)
//         {
//             checkForFullPath(argv, envp);
//         }
//         else
//         {
//             if (execve(cmd, argv, envp) == -1)
//             {
//                 // ===============CHECK==========================
//                 printString(argv[0]), printNum(count);
//                 printString(": otside found\n");
//                 printString(": "), printString(cmd);
//                 printString(": not found\n");
//                 perror("execve"), exit(EXIT_FAILURE);
//             }
//             else
//             {
//                 printString(": otside found\n");
//             }
//         }
//         exit(EXIT_FAILURE);
//     }
//     else if (pid < 0)
//         perror("fork");
//     else
//         waitpid(pid, &status, 0);

//     return status;
// }

// char **getPathDirectories()
// {
//     char *path = getenv("PATH");

//     if (path == NULL)
//     {
//         char *error_msg = "Error: PATH environment variable not found.\n";
//         write(STDERR_FILENO, error_msg, strlen(error_msg));
//         return NULL;
//     }

//     char *path_copy = strdup(path);

//     if (path_copy == NULL)
//     {
//         perror("strdup");
//         return NULL;
//     }

//     char **directories = malloc(MAX_PATH_LENGTH * sizeof(char *));
//     if (directories == NULL)
//     {
//         perror("malloc");
//         free(path_copy);
//         return NULL;
//     }

//     int count = 0;
//     char *token = strtok(path_copy, ":");
//     while (token != NULL)
//     {
//         directories[count] = strdup(token);
//         if (directories[count] == NULL)
//         {
//             perror("strdup");
//             // Free previously allocated memory
//             for (int i = 0; i < count; i++)
//             {
//                 free(directories[i]);
//             }
//             free(directories);
//             free(path_copy);
//             return NULL;
//         }
//         count++;
//         token = strtok(NULL, ":");
//     }

//     directories[count] = NULL;

//     free(path_copy);

//     return directories;
// }

void checkForFullPath(char *argv[], char *envp[])
{
    char *path = getenv("PATH");
    char path_copy[strlen(path) + 1];
    strcpy(path_copy, path);
    char *dir = strtok(path_copy, ":");

    while (dir != NULL)
    {
        char full_path[256];

        // Construct full_path by copying dir and appending argv[0]
        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, argv[0]);

        if (access(full_path, X_OK) == 0)
        {
            if (_strcmp(argv[0], "cd") != 0 && _strcmp(argv[0], "cd ..") != 0)
            {
                if (execve(full_path, argv, envp) == -1)
                {
                    // Print an error message if execve fails
                    printString("Error: ");
                    perror(argv[0]);
                }
            }
            return; // Return without checking other directories
        }
        dir = strtok(NULL, ":");
    }

    // If the loop completes without finding the command and it's not a "cd" or "cd .." command, print an error message
    if (_strcmp(argv[0], "cd") != 0 && _strcmp(argv[0], "cd ..") != 0)
    {
        printString("Error: ");
        printString(argv[0]);
        printString(": command not found\n");
    }
}

// void checkForFullPath(char *argv[], char *envp[])
// {
//     char *path = getenv("PATH");
//     char path_copy[strlen(path) + 1];
//     strcpy(path_copy, path);
//     char *dir = strtok(path_copy, ":");

//     while (dir != NULL)
//     {
//         char full_path[256];

//         // Construct full_path by copying dir and appending argv[0]
//         strcpy(full_path, dir);
//         strcat(full_path, "/");
//         strcat(full_path, argv[0]);

//         if (access(full_path, X_OK) == 0)
//         {
//             if (execve(full_path, argv, envp) == -1)
//             {
//                 // Print an error message if execve fails
//                 printString("Error: ");
//                 perror(argv[0]);
//                 return; // Return without exiting the loop
//             }
//             return; // Return without checking other directories
//         }
//         dir = strtok(NULL, ":");
//     }

//     // If the loop completes without finding the command, print an error message
//     printString("Error: ");
//     printString(argv[0]);
//     printString(": command not found\n");
// }

// void checkForFullPath(char *argv[], char *envp[])
// {
//     char *path = getenv("PATH");
//     char path_copy[_strlen(path) + 1];
//     _strcpy(path_copy, path);
//     char *dir = _strtok(path_copy, ":");

//     while (dir)
//     {
//         char full_path[256];

//         // Construct full_path by copying dir and appending argv[0]
//         _strcpy(full_path, dir);
//         _strcat(full_path, "/");
//         _strcat(full_path, argv[0]);

//         // if (access(full_path, X_OK) == 0)
//         // {
//         //     execve(full_path, argv, envp);
//         //     perror("execve");
//         //     exit(EXIT_FAILURE);
//         // }
//         if (access(full_path, X_OK) == 0)
//         {
//             if (execve(full_path, argv, envp))
//             {
//                 printString("Error eroor lama\n");
//                 perror("execve");
//                 exit(EXIT_FAILURE);
//             }
//             printString("Ouside eroor lama\n");
//         }
//         dir = _strtok(NULL, ":");
//     }
// }

// void checkForFullPath(char *argv[], char *envp[])
// {
//     char *path = getenv("PATH");
//     char path_copy[_strlen(path) + 1];
//     _strcpy(path_copy, path);
//     char *dir = _strtok(path_copy, ":");

//     while (dir != NULL)
//     {
//         char full_path[256];

//         snprintf(full_path, sizeof(full_path), "%s/%s", dir, argv[0]);
//         if (access(full_path, X_OK) == 0)
//         {
//             execve(full_path, argv, envp);
//             perror("execve");
//             exit(EXIT_FAILURE);
//         }
//         dir = _strtok(NULL, ":");
//     }
// }

void checkExitChangedir(int argc, char *argv[])
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
}

// int main(int argc, char *argv[], char *envp[])
// {
//     char *ms_linePointer = NULL;
//     size_t ms_lineSize = 0;
//     ssize_t read;
//     int count = 0;
//     bool ctrlCPressed = false;

//     signal(SIGINT, handleCtrlCSignal);

//     while (true)
//     {
//         count++;
//         prompt();
//         read = _getline(&ms_linePointer, &ms_lineSize, stdin);
//         if (read == -1)
//             free(ms_linePointer),
//                 printString("\n"), exit(2);
//         ms_linePointer[read - 1] = '\0';

//         if (_strlen(ms_linePointer) == 0)
//             continue;

//         char *input_argv[64];
//         size_t input_argc = splitToTokens(ms_linePointer, input_argv, " ");
//         execCommand(input_argc, input_argv, envp, count, &ctrlCPressed);
//     }

//     free(ms_linePointer);
//     return (0);
// }

int main(int argc, char *argv[], char *envp[])
{
    char *ms_linePointer = NULL;
    size_t ms_lineSize = 0;
    ssize_t read;
    int count = 0;
    bool ctrlCPressed = false;

    while (true)
    {
        count++;
        prompt();
        read = _getline(&ms_linePointer, &ms_lineSize, stdin);
        if (read == -1)
        {
            free(ms_linePointer);
            printString("\n");
            exit(2);
        }
        ms_linePointer[read - 1] = '\0';

        if (_strlen(ms_linePointer) == 0)
            continue;

        char *input_argv[64];
        size_t input_argc = splitToTokens(ms_linePointer, input_argv, " ");

        // Check if the user wants to exit the shell
        if (_strcmp(input_argv[0], "exit") == 0)
        {
            free(ms_linePointer);
            exit(0);
        }

        // Check if the command contains '/'
        if (_strchr(input_argv[0], '/') != NULL)
        {
            // Directly execute the command
            execCommand(input_argc, input_argv, envp, count, &ctrlCPressed, STDIN_FILENO, STDOUT_FILENO);
        }
        else
        {
            // Search for the command in PATH and execute if found
            checkForFullPath(input_argv, envp);
        }
    }

    // The loop should never reach here, but free resources just in case
    free(ms_linePointer);
    return 0;
}
