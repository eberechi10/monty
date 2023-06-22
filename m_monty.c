#include "monty.h"

#include <stdio.h>


stack_t *head = NULL;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);


/**
  * main - the entry point.
  *
  * @argc: the arguments passed to program.
  * @argv: the vector containing arguments to pass.
  *
  * Return: returns always 0.
  */

int main(int argc, char *argv[])
{
	FILE *mty_file = NULL;
	unsigned int line_num = 0;
	int cmd = 0, state = 0;
	size_t c_len = 0;
	char *filename = NULL, *opcd = NULL, *node = NULL, *scan_line = NULL;

	mty_file = get_file(filename);
	filename = argv[1];
	get_num_args(argc);

	while ((cmd = getline(&scan_line, &c_len, mty_file)) != -1)
	{
		line_num++;
		opcd = strtok(scan_line, " \t\n");
		if (opcd)
		{
			if (opcd[0] == '#')
				continue;

			node = strtok(NULL, " \t\n");
			state = hold_exe(opcd, node, line_num, state);

			if (state >= 100 && state < 300)
			{
				fclose(mty_file);
				hold_err(state, opcd, line_num, scan_line);
			}
		}

	}

	reles_stack();
	free(scan_line);
	fclose(mty_file);
	return (0);
}
