#include "monty.h"


/**
  * get_digits - verify all chars in a string if theres digits.
  *
  * @s: the string.
  *
  * Return: if success 1, otherwise 0
  */

int get_digits(char *s)
{
	while (*s != '\0')
	{
		if (s[0] == '-')
		{
			s++;
			continue;
		}

		if (isdigit(*s) == 0)
			return (0);

		s++;
	}

	return (1);
}


/**
  * get_push_node - gets the node for push instruction.
  *
  * @node: node to be validated.
  *
  * Return: if success 0, otherwise error code.
  */
int get_push_node(char *node)
{
	if (node == NULL || get_digits(node) == 0)
		return (PUSH_ER);

	return (VALID_DATA);
}


/**
  * get_num_args - gets arguments passed into the interpreter.
  *
  * @argn: number of args to pass.
  *
  * Return: it returns nothing.
  */

void get_num_args(int argn)
{
	if (argn != MIN_ARGS)
		hold_err(USAGE_ER, NULL, 0, NULL);
}


/**
  * get_scan_permission - Checks if the user has permissions to read the file.
  *
  * @path: path to the file.
  *
  * Return: it returns nothing.
  */

void get_scan_permission(char *path)
{
	if (access(path, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
}
