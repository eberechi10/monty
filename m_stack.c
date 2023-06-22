#include "monty.h"

/**
  * stack_counter - function to count elements in the stack.
  *
  * @stack: the stack head
  *
  * Return: the counts of elements.
  */

unsigned int stack_counter(stack_t *stack)
{
	stack_t *new;
	unsigned int len;

	len = 0;
	new = stack;


	while (new)
	{
		len++;
		new = new->next;
	}

	return (len);
}


/**
  * reles_stack - a function that set stack free(doubly-linked list)
  *
  * Return: it returns nothing
  */

void reles_stack(void)
{
	stack_t *new = NULL;

	if (head)
	{
		new = head;

		while (new)
		{
			head = head->next;
			free(new);

			new = head;
		}
	}
}
