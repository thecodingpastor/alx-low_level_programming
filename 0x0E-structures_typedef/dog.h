#ifndef DOG_H
#define DOG_H

/**
 * struct dog - describes a dog
 * @name: arg 1
 * @age: arg 2
 * @owner: arg 3
 *
 * Description: defines a struct with three items
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
