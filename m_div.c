#include "monty.h"

/**
 * _div - func to div second top element by the top element of stack
 *
 * @stack: the stack head.
 * @line_number: Line number of the command.
 *
 * Return: it returns nothing.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *elm = *stack;
	unsigned int x, y, len;

	x = 0;
	y = 0;
	len = 0;

	len = stack_counter(*stack);

	if (len < 2)
		hold_err(DIV_ER, NULL, line_number, NULL);

	x = elm->n;

	if (x == 0)
		hold_err(ZERO_ER_DIV, NULL, line_number, NULL);

	y = elm->next->n;
	elm->next->n = y / x;

	*stack = elm->next;
	free(elm);
}
