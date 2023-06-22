#include "monty.h"

/**
 * _pall - function to get all values on the stack, from top of stack.
 *
 * @stack: The head of the stack
 * @line_number: Line number of the command.
 *
 * Return: it returns nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{

	stack_t *new = NULL;

	(void) line_number;


		new = *stack;
		while (new)
		{
			printf("%d\n", new->n);
			new = new->next;
		}
}
