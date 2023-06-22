#include "monty.h"

/**
  * put_op - function to select the operation Monty instruction.
  *
  * @s: instruction to be executed
  *
  * Return: if success the executed function, otherwise NULL.
  */

void (*put_op(char *s))(stack_t **, unsigned int)
{
	instruction_t mop[] = {
		{ "pushqueue", _pushqueue },
		{ "pchar", _pchar },
		{ "div", _div },
		{ "push", _push },
		{ "pall", _pall },
		{ "pint", _pint },
		{ "swap", _swap },
		{ "pstr", _pstr },
		{ "rotl", _rotl },
		{ "rotr", _rotr },
		{ "pop", _pop },
		{ "add", _add },
		{ "nop", _nop },
		{ "sub", _sub },
		{ "mul", _mul },
		{ "mod", _mod },
		{ NULL, NULL }
	};
	int index = 0;

	while (mop[index].opcode)
	{
		if (strcmp(s, mop[index].opcode) == 0)

			return (mop[index].f);

		index++;
	}

	return (NULL);
}
