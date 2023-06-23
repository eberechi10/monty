#define _GNU_SOURCE

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

global_t mtys;

/**
 * main - it is the entry point.
 *
 * @argc: the count argument
 * @argv: the argument vector.
 *
 * Return: if success 0.
 */
int main(int argc, char *argv[])
{

	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *filed;
	ssize_t mlin = 0;
	size_t size = 256;
	char *node[2] = {NULL, NULL};

	filed = ver_input(argc, argv);
	start_mtys(filed);
	mlin = getline(&mtys.buf, &size, filed);
	while (mlin != -1)
	{
		node[0] = strtok(mtys.buf, " \t\n");

		if (node[0] && node[0][0] != '#')
		{
			f = sel_opcode(node[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", mtys.datas);
				fprintf(stderr, "unknown instruction %s\n", node[0]);
				reles_mtys();
				exit(EXIT_FAILURE);
			}
			mtys.arg_m = strtok(NULL, " \t\n");
			f(&mtys.head, mtys.datas);
		}
		mlin = getline(&mtys.buf, &size, filed);
		mtys.datas++;
	}

	reles_mtys();

	return (0);
}


/**
 * reles_mtys - funct to free global variables.
 *
 * Return: nothing.
 */
void reles_mtys(void)
{
	free_list(mtys.head);
	free(mtys.buf);
	fclose(mtys.filed);
}

/**
 * start_mtys - it starts the global variables.
 *
 * @filed: the file desc.
 *
 * Return: nothing.
 */
void start_mtys(FILE *filed)
{
	mtys.nline = 1;
	mtys.datas = 1;
	mtys.arg_m = NULL;
	mtys.head = NULL;
	mtys.filed = filed;
	mtys.buf = NULL;
}

/**
 * ver_input - func to check file exists and if file can be opened.
 *
 * @argc: counts the argument.
 * @argv: the vector of the argument.
 *
 * Return: the structure.
 */
FILE *ver_input(int argc, char *argv[])
{
	FILE *filed;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filed = fopen(argv[1], "r");

	if (filed == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (filed);
}


