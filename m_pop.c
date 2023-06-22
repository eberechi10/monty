#include "monty.h"

/**
 * _pop - a functoin to remove top element in a stack.
 *
 * @stack: the stack head.
 * @line_number: Line number of the commands
 *
 * Return: it returns nothing.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack, *elm = NULL;

	if (*stack == NULL)
		hold_err(POP_ER, NULL, line_number, NULL);

	elm = new;

	if (new->next)
	{
		new = new->next;
		new->prev = elm->prev;

		*stack = new;
	}
	else
	{
		*stack = NULL;
	}

	free(elm);
}
