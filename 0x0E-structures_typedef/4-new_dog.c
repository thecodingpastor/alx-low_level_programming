#include "dog.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * new_dog - creates a new dog.
 * @name: arg 1
 * @age: arg 2
 * @owner: arg 3
 *
 * Return: pointer or NULL
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *my_dog;
	int i, j;

	i = strlen(name);
	j = strlen(owner);

	my_dog = malloc(sizeof(dog_t));

	if (my_dog == NULL)
		return (NULL);

	my_dog->name = malloc(sizeof(char) * (i + 1));

	if (my_dog->name == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	my_dog->owner = malloc(sizeof(char) * (j + 1));
	if (my_dog->owner == NULL)
	{
		free(my_dog);
		free(my_dog->name);
		return (NULL);
	}
	strcpy(my_dog->name, name);
	strcpy(my_dog->owner, owner);
	my_dog->age = age;
	return (my_dog);
}
