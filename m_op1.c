#include "monty.h"
#include <stdio.h>

/**
 * pchar - func to print char value of the first element
 *
 * @stack: linked list head
 * @count: line number.
 *
 * Return: nothing.
 */
void pchar(stack_t **stack, unsigned int count)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - funct to print string of the stack
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing.
 */
void pstr(stack_t **stack, unsigned int count)
{
	stack_t *new;
	(void)count;

	new = *stack;

	while (new && new->n > 0 && new->n < 128)
	{
		printf("%c", new->n);
		new = new->next;
	}

	printf("\n");
}



/**
 * mod - computes rest of the div of the 2nd element wth top of the stack.
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int count)
{
	int x;
	stack_t *new = NULL;

	x = 0;
	new = *stack;

	for (; new != NULL; new = new->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	new->n %= (*stack)->n;
	pop(stack, count);
}



/**
 * _div - func to div the second element by the top element of the stack
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing.
 */
void _div(stack_t **stack, unsigned int count)
{
	int x = 0;
	stack_t *new = NULL;

	new = *stack;

	for (; new != NULL; new = new->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	new->n /= (*stack)->n;
	pop(stack, count);
}


/**
 * mul - multiply the top element to the second element of the stack.
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothig.
 */
void mul(stack_t **stack, unsigned int count)
{
	int x;
	stack_t *new = NULL;

	x = 0;

	new = *stack;

	for (; new != NULL; new = new->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	new->n *= (*stack)->n;
	pop(stack, count);

}

