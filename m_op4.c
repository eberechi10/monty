#include "monty.h"

/**
 * rotr - funtcion to reverse the stack
 *
 * @stack: linked list head.
 * @count: line number.
 *
 * Return: nothing.
 */
void rotr(stack_t **stack, unsigned int count)
{
	stack_t *new = NULL;
	(void)count;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	new = *stack;

	for (; new->next != NULL; new = new->next)
		;

	new->prev->next = NULL;
	new->next = *stack;
	new->prev = NULL;
	(*stack)->prev = new;
	*stack = new;
}



/**
 * rotl - func to rotate first ele to the bottom and the second to the top.
 *
 * @stack: linked list head
 * @count: line number.
 *
 * Return: nothing.
 */
void rotl(stack_t **stack, unsigned int count)
{
	stack_t *a = NULL;
	stack_t *b = NULL;
	(void)count;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	a = (*stack)->next;
	b = *stack;

	for (; b->next != NULL; b = b->next)
		;

	a->prev = NULL;
	b->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = b;
	*stack = a;
}


