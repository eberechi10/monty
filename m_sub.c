#include "monty.h"

/**
 * _sub - a function to sub top element from 2nd element
 *
 * @stack: the stack head
 * @line_number: Line number of the command
 *
 * Return: it returns nothing.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	unsigned int p, i, len;
	stack_t *elm = *stack;

	p = 0;
	i = 0;
	len = 0;

	len = stack_counter(*stack);

	if (len < 2)
		hold_err(SUB_ER, NULL, line_number, NULL);

	p = elm->n;
	i = elm->next->n;

	elm->next->n = i - p;
	*stack = elm->next;

	free(elm);
}
