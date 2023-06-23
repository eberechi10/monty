#include "monty.h"


/**
 * realloc_m - it changes size of the contents and copy content.
 *
 * @ptr: the pointer to reallocate
 * @old: old bytes
 * @new: new bytes.
 *
 * Return: it returns nothing.
 */
void *realloc_m(void *ptr, unsigned int old, unsigned int new)
{
	char *s = NULL;
	unsigned int index;

	if (new == old)
		return (ptr);
	if (ptr == NULL)
	{
		s = malloc(new);
		if (!s)
			return (NULL);
		return (s);
	}
	if (new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new > old)
	{
		s = malloc(new);
		if (!s)
			return (NULL);
		for (index = 0; index < old; index++)
			s[index] = *((char *)ptr + index);
		free(ptr);
	}
	else
	{
		s = malloc(new);
		if (!s)
			return (NULL);
		for (index = 0; index < new; index++)
			s[index] = *((char *)ptr + index);
		free(ptr);
	}
	return (s);
}


/**
 * calloc_m - funct to join tow strings.
 *
 * @count: its the number of strings
 * @size: the type of strings.
 *
 * Return: it returns nothing.
 */
void *calloc_m(unsigned int count, unsigned int size)
{
	void *ptr = NULL;
	unsigned int index;

	if (count == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (index = 0; index < (count * size); index++)
	{
		*((char *)(ptr) + index) = 0;
	}
	return (ptr);
}


