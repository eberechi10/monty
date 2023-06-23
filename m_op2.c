#include "monty.h"

#include <stdio.h>

/**
 * pop - funct to remove top element of the stack.
 *
 * @stack: linked list head.
 * @count: line number
 *
 * Return: nothing.
 */
void pop(stack_t **stack, unsigned int count)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}
	new = *stack;
	*stack = (*stack)->next;
	free(new);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: linked list head.
 * @count: line number
 *
 * Return: nothing.
 */
void swap(stack_t **stack, unsigned int count)
{
	int i = 0;
	stack_t *new = NULL;

	new = *stack;

	for (; new != NULL; new = new->next, i++)
		;

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	new = *stack;
	*stack = (*stack)->next;
	new->next = (*stack)->next;
	new->prev = *stack;
	(*stack)->next = new;
	(*stack)->prev = NULL;
}


/**
 * push - it pushs element to the stack
 *
 * @stack: linked list head
 * @line_number: line number
 * Return: nothing to return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int x, y;

	if (!mtys.arg_m)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	for (y = 0; mtys.arg_m[y] != '\0'; y++)
	{
		if (!isdigit(mtys.arg_m[y]) && mtys.arg_m[y] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			reles_mtys();
			exit(EXIT_FAILURE);
		}
	}

	x = atoi(mtys.arg_m);

	if (mtys.nline == 1)
		add_start_node(stack, x);
	else
		add_last_node_stack(stack, x);
}

/**
 * pall - funct to print every values on stack
 *
 * @stack: linked list head.
 * @line_number: line numbers
 *
 * Return: nothing return.
 */
void pall(stack_t **stack, unsigned int line_number)
{


	stack_t *new = *stack;
	(void)line_number;

	while (new)
	{
		printf("%d\n", new->n);

		new = new->next;
	}
}

/**
 * pint - funct to print value from top of the stack
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing.
 */
void pint(stack_t **stack, unsigned int count)
{
	(void)count;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: ", count);
		fprintf(stderr, "can't pint, stack empty\n");
		reles_mtys();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);

}


