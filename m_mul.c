#include "monty.h"

/**
 * _mul -func to Multipy 2nd top element with the top element in stack
 *
 * @stack: the stack head
 * @line_number: Line number of the command
 *
 * Return: it returns nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *elm = *stack;
	unsigned int x, y, len;

	x = 0;
	y = 0;
	len = 0;

	len = stack_counter(*stack);

	if (len < 2)
		hold_err(MUL_ER, NULL, line_number, NULL);

	x = elm->n;
	y = elm->next->n;

	elm->next->n = x * y;
	*stack = elm->next;

	free(elm);
}
