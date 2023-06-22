#include "monty.h"

#include <stddef.h>
#include <string.h>

/**
  * hold_big_errors - control the errors for pchar.
  *
  * @errno: error code specifier.
  * @counter: line where the error occurred
  *
  * Return: it returns nothing.
  */
void hold_big_errors(int errno, unsigned int counter)
{
	switch (errno)
	{
		case F_PCHAR_ER:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
			break;
		case E_PCHAR_ER:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
			break;
		default:
			break;
	}
}


/**
  * hold_err - func to get error and prints errors codes.
  *
  * @errno: the error code custom.
  * @opcd: The operation code.
  * @counter: The line on which the error occurred.
  *
  * @scan_line: The reserved error line buffer
  *
  * Return: it returns nothing
  */

void hold_err(int errno, char *opcd, unsigned int counter, char *scan_line)
{
	if (errno >= 100 && errno < 200)
		hold_malloc_er(errno, opcd, counter);
	else if (errno >= 200 && errno <= 210)
		hold_op_err(errno, counter);
	else if (errno >= 211 && errno <= 220)
		hold_big_errors(errno, counter);
	else
		return;

	reles_stack();

	if (scan_line)
		free(scan_line);

	exit(EXIT_FAILURE);
}

/**
  * hold_malloc_er - controls malloc errors.
  * @errno: error code specifier.
  * @opcd: operationalcode.
  * @counter: the line where the error occurred.
  *
  * Return: it returns nothing.
  */

void hold_malloc_er(int errno, char *opcd, unsigned int counter)
{
	switch (errno)
	{
		case INVALID_ER:
			fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcd);
			break;
		case MALLOC_ER:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  * hold_op_err - controls errors for opcode operations.
  *
  * @errno: error code specifier.
  * @counter: line where the error occurred.
  *
  * Return: it returns nothing.
  */

void hold_op_err(int errno, unsigned int counter)
{
	switch (errno)
	{
		case USAGE_ER:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case PUSH_ER:
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			break;
		case PINT_ER:
			fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
			break;
		case POP_ER:
			fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
			break;
		case SWAP_ER:
			fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
			break;
		case ADD_ER:
			fprintf(stderr, "L%d: can't add, stack too short\n", counter);
			break;
		case SUB_ER:
			fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
			break;
		case DIV_ER:
			fprintf(stderr, "L%d: can't div, stack too short\n", counter);
			break;
		case ZERO_ER_DIV:
			fprintf(stderr, "L%d: division by zero\n", counter);
			break;
		case MUL_ER:
			fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
			break;
		case MOD_ER:
			fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
			break;
		default:
			break;
	}
}
