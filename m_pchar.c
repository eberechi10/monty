#include "monty.h"

/**
  * _pchar - function to get the char at top of stack,followed by nline.
  *
  * @stack: the stack head
  * @line_number: Line number of the commands
  *
  * Return: it returns nothing
  */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		hold_err(E_PCHAR_ER, NULL, line_number, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		hold_err(F_PCHAR_ER, NULL, line_number, NULL);
}
