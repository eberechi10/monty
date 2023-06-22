#ifndef _MONTY_H
#define _MONTY_H

#define VALID_DATA		0
#define MIN_ARGS		2

#define INVALID_ER	        100
#define MALLOC_ER	        101
#define INVLID_PARM_ER	        102
#define STACK_METHD		300
#define QUEUE_METHD		301

#define USAGE_ER		200
#define PUSH_ER		        201
#define PINT_ER		        202
#define POP_ER			203
#define SWAP_ER		        204
#define ADD_ER			205
#define SUB_ER			206
#define DIV_ER			207
#define ZERO_ER_DIV	        208
#define MUL_ER			209
#define MOD_ER			210
#define F_PCHAR_ER		211
#define E_PCHAR_ER		212

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void _add(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
int get_digits(char *s);
int get_push_node(char *node);
void get_num_args(int argn);
void get_scan_permission(char *path);
void hold_big_errors(int errno, unsigned int counter);
void hold_err(int errno, char *opcd, unsigned int counter, char *scan_line);
void hold_malloc_er(int errno, char *opcd, unsigned int counter);
void hold_op_err(int errno, unsigned int counter);
int hold_exe(char *op_cd, char *node, unsigned int counter, int indc);
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int node);
void _pushqueue(stack_t **stack, unsigned int data);
void _rotr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void (*put_op(char *s))(stack_t **, unsigned int);
unsigned int stack_counter(stack_t *stack);
void reles_stack(void);
void _sub(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
FILE *get_file(char *path);

#endif /* _MONTY_H_ */
