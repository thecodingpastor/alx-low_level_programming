#include "dog.h"

/**
 * init_dog - initialize a variable of type struct dog
 *
 * @d: arg 1
 * @name: arg 2
 * @age: arg 3
 * @owner: arg 4
 *
 * Description: function that initializes a struct
 * which takes three args
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
