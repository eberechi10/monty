#include "monty.h"

/**
  * _rotr - a funtcion to rotate stack to the bottom
  *
  * @stack: the stack head.
  * @line_number: Line number of the commands
  *
  * Return: it returns nothing.
  */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *end = NULL;

	(void) line_number;


	if (*stack && (*stack)->next)
	{
		end = *stack;

		while (end->next != NULL)
			end = end->next;

		end->prev->next = NULL;
		end->next = *stack;

		*stack = end;
	}
}

/**
  * _rotl - a function to rotates stack to the top
  * @stack: the stack head.
  * @line_number: Line number of the commands
  *
  * Return: it returns nothing.
  */
void _rotl(stack_t **stack, unsigned int line_number)
{

	unsigned int elm;
	stack_t *new = *stack;
	(void) line_number;


	elm = 0;

	if (new && new->next)
	{
		while (new->next)
		{
			elm = new->n;

			new->n = new->next->n;
			new->next->n = elm;

			new = new->next;
		}
	}
}
