#include <stdlib.h>
/**
 * wordLen - gets the index marking the end of the first word
 * in a string
 * @str: string to be checked
 * Return: The index marking the end of the first word
 */

int wordLen(char *str)
{
	int i = 0, len = 0;

	while (*(i + str) && *(i + str) != ' ')
		i++, len++;
	return (len);
}

/**
 * count - counts the number of words in a string
 * @str: string to search
 * Return: number of words
 */

int count(char *str)
{
	int i = 0, len = 0, numWords = 0;

	for (i = 0; *(str + i); i++)
		len++;
	for (i = 0; i < len; i++)
	{
		if (*(i + str) != ' ')
			numWords++, i += wordLen(str + i);
	}
	return (numWords);
}
/**
 * strtow - function that splits a string into words.
 * @str: string to be split
 * Return: pointer, NULL or ""
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, numOfWords, letters;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	numOfWords = count(str);

	if (numOfWords == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (numOfWords + 1));

	if (words == NULL)
		return (NULL);
	for (j = 0; j < numOfWords; j++)
	{
		while (str[i] == ' ')
			i++;
		letters = wordLen(str + i);

		words[j] = malloc(sizeof(char) * (letters + 1));

		if (words[j] == NULL)
		{
			for (; j >= 0; j--)
				free(words[j]);
			free(words);
			return (NULL);
		}
		for (k = 0; k < letters; k++)
			words[j][k] = str[i++];
		words[j][k] = '\0';
		}
	words[j] = NULL;
	return (words);
}
