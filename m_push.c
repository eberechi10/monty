#include "monty.h"

/**
  * _push - a function to add node to the beginning of stack.
  *
  * @stack: the stack head.
  * @node: node to push to stack
  *
  * Return: it returns nothing.
  */
void _push(stack_t **stack, unsigned int node)
{
	stack_t *node_c = NULL;

	node_c = malloc(sizeof(stack_t));

	if (!node_c)
		hold_err(MALLOC_ER, NULL, 0, NULL);

	node_c->n = node;
	if (*stack)
	{
		node_c->next = *stack;

		node_c->prev = (*stack)->prev;
		(*stack)->prev = node_c;
		*stack = node_c;
		return;
	}

	node_c->next = *stack;
	node_c->prev = NULL;

	*stack = node_c;
}

/**
  * _pushqueue - function to add a node to the end of stack.
  *
  * @stack: the stack head.
  * @node: node to push on the stack
  *
  * Return: it return nothing.
  */
void _pushqueue(stack_t **stack, unsigned int node)
{
	stack_t *new = NULL, *node_c = NULL;

	node_c = malloc(sizeof(stack_t));

	if (!node_c)
		hold_err(MALLOC_ER, NULL, 0, NULL);

	node_c->n = node;

	if (*stack)
	{
		new = *stack;
		while (new->next != NULL)
			new = new->next;

		node_c->next = NULL;
		node_c->prev = new;

		new->next = node_c;
		return;
	}

	node_c->next = *stack;

	node_c->prev = NULL;
	*stack = node_c;
}
