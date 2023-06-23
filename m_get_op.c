#include "monty.h"

/**
 * sel_opcode - funct to select correct opcode.
 *
 * @opcd: the opcode to be passed.
 *
 * Return: address of function to executes opcode
 */
void (*sel_opcode(char *opcd))(stack_t **stack, unsigned int line_number)
{
	instruction_t mymty[] = {
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"queue", queue},
		{"stack", stack},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int index;

	for (index = 0; mymty[index].opcode; index++)
	{
		if (_strcmp(mymty[index].opcode, opcd) == 0)
			break;
	}

	return (mymty[index].f);

}
