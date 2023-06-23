#include "monty.h"

#include <stdio.h>

/**
 * nop - funct that doesn't do anythinhg
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: no return
 */
void nop(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;
}


/**
 * sub - sub top element to the second top element of the stack
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int count)
{
	int x;
	stack_t *new = NULL;

	x = 0;

	new = *stack;

	for (; new != NULL; new = new->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	new->n -= (*stack)->n;
	pop(stack, count);
}



/**
 * queue - funct to format node to a queue filo.
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing.
 */
void queue(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;

	mtys.nline = 0;
}

/**
 * stack - funct to format node to a stack (lifo)
 *
 * @stack: linked list head
 * @count: line number.
 *
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;

	mtys.nline = 1;
}

/**
 * add - funct to add top two elements of the stack
 *
 * @stack: linked list head
 * @count: line number
 *
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int count)
{
	int x = 0;
	stack_t *new = NULL;

	new = *stack;

	for (; new != NULL; new = new->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	new->n += (*stack)->n;
	pop(stack, count);
}


