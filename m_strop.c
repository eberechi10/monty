#include "monty.h"


/**
 * strtok - funct to cut string to tokens depending on delimit.
 *
 * @s: the string
 * @del: the delimit.
 *
 * Return: the first partition.
 */
char *strtok(char *s, char *del)
{
	static char *monty_f;
	int index, x;

	x = 0;
	index = 0;

	if (!s)
		s = monty_f;
	while (s[index] != '\0')
	{
		if (get_char(del, s[index]) == 0 && s[index + 1] == '\0')
		{
			monty_f = s + index + 1;
			*monty_f = '\0';
			s = s + x;
			return (s);
		}
		else if (get_char(del, s[index]) == 0 && get_char(del, s[index + 1]) == 0)
			index++;
		else if (get_char(del, s[index]) == 0 && get_char(del, s[index + 1]) == 1)
		{
			monty_f = s + index + 1;
			*monty_f = '\0';
			monty_f++;
			s = s + x;
			return (s);
		}
		else if (get_char(del, s[index]) == 1)
		{
			x++;
			index++;
		}
	}
	return (NULL);
}



/**
 * _strcmp - a function to compare two strings.
 *
 * @s1: first string.
 * @s2: second string
 *
 * Return: 0 if s1 and s2, otherwise 1.
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] == s2[index] && s1[index]; index++)
		;
	if (s1[index] > s2[index])
		return (1);

	if (s1[index] < s2[index])
		return (-1);

	return (0);
}

/**
 * get_char - funct to look if a char in string.
 *
 * @s: string to review
 * @c: the char.
 *
 * Return: 1 if success, otherwise 0.
 */
int get_char(char *s, char c)
{
	int sum;

	sum = 0;

	while (s[sum] != '\0')
	{
		if (s[sum] == c)
		{
			break;
		}
		sum++;
	}

	if (s[sum] == c)
		return (1);

	else
		return (0);
}


