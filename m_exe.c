#include "monty.h"

/**
  * hold_exe - func that instruct the op to be execute.
  *
  * @op_cd: code to be execute.
  * @node: node with instruction.
  *
  * @counter: count of number of command
  * @indc: it indicate push opera will be stack or queue.
  *
  * Return: if success 0, otherwise errcode.
  */

int hold_exe(char *op_cd, char *node, unsigned int counter, int indc)
{
	void (*func_op)(stack_t **, unsigned int);
	int op_state = 0;

	if (strcmp(op_cd, "stack") == 0)
		return (STACK_METHD);
	else if (strcmp(op_cd, "queue") == 0)
		return (QUEUE_METHD);

	func_op = put_op(op_cd);
	if (func_op)
	{
		if (strcmp(op_cd, "_push") == 0)
		{
			op_state = get_push_node(node);
			if (op_state == PUSH_ER)
				return (PUSH_ER);

			if (indc != 0 && indc == QUEUE_METHD)
				func_op = put_op("_pushqueue");

			func_op(&head, atoi(node));
		}
		else
			func_op(&head, counter);

		return (indc);
	}

	return (INVALID_ER);
}
