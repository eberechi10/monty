#include "monty.h"

/**
  * _pstr - a func to print string from the top of stack followed by nline
  *
  * @stack: the stack head.
  * @line_number: Line number of the commands
  *
  * Return: it returns nothing.
  */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void) line_number;

	while (new)
	{
		if (new->n == 0 || new->n < 0 || new->n > 127)
			break;

		printf("%c", new->n);
		new = new->next;

	}

	printf("\n");
}
