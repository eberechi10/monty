#include "monty.h"

/**
 * _pint - function to get value from top of stack followed by new line.
 *
 * @stack: the stack head.
 * @line_number: Line number of the commands
 *
 * Return: it returns nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)

		hold_err(PINT_ER, NULL, line_number, NULL);

	printf("%d\n", (*stack)->n);
}
