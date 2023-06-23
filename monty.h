#ifndef MONTY_H
#define MONTY_H

#define _P_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_mtys - it is the montys struct useed in the funct.
 * @nline: it is the stack or the queue.
 * @datas: the line
 * @arg_m: the second arg inside the line
 * @head: it is linked list.
 * @filed: the descr of the file.
 * @buf: it is the string
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO.
 */
typedef struct global_mtys
{
	stack_t *head;
	FILE *filed;
	char *buf;
	int nline;
	unsigned int datas;
	char *arg_m;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t mtys;

int main(int argc, char *argv[]);
void reles_mtys(void);
void start_mtys(FILE *filed);
FILE *ver_input(int argc, char *argv[]);
void free_list(stack_t *head);
stack_t *add_last_node_stack(stack_t **head, const int n);
stack_t *add_start_node(stack_t **head, const int n);
void (*sel_opcode(char *opcd))(stack_t **stack, unsigned int line_number);
void *realloc_m(void *ptr, unsigned int old, unsigned int new);
void *calloc_m(unsigned int count, unsigned int size);
void pchar(stack_t **stack, unsigned int count);
void pstr(stack_t **stack, unsigned int count);
void mod(stack_t **stack, unsigned int count);
void _div(stack_t **stack, unsigned int count);
void mul(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int count);
void swap(stack_t **stack, unsigned int count);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int count);
void nop(stack_t **stack, unsigned int count);
void sub(stack_t **stack, unsigned int count);
void queue(stack_t **stack, unsigned int count);
void stack(stack_t **stack, unsigned int count);
void add(stack_t **stack, unsigned int count);
void rotr(stack_t **stack, unsigned int count);
void rotl(stack_t **stack, unsigned int count);
char *strtok(char *s, char *del);
int _strcmp(char *s1, char *s2);
int get_char(char *s, char c);

#endif
