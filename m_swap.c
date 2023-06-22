#include "monty.h"

/**
 * _swap - function to swap top two elements of stack.
 *
 * @stack: the stack head.
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	unsigned int len, elm;

	len = 0;
	elm = 0;

	len = stack_counter(*stack);

	if (len < 2)
		hold_err(SWAP_ER, NULL, line_number, NULL);

	if (*stack)
	{
		elm = (*stack)->n;

		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = elm;
	}
}
