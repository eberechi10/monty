#include "monty.h"

/**
  * get_file - a function to get file to interpret the commands.
  *
  * @path: the file to get.
  *
  * Return: the get file.
  */
FILE *get_file(char *path)
{
	FILE *dfil = NULL;

	get_scan_permission(path);

	dfil = fopen(path, "r");

	if (!dfil)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}

	return (dfil);
}
