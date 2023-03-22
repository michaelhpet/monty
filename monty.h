#ifndef _MONTY_H_
#define _MONTY_H_

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * struct state_s - state struct for storing global variables in the program
 * @data_type: data type in use (stack or queue)
 * @head: head node of doubly-linked list used for data
 * @tail: tail node of doubly-linked list used for data
 * @argument: argument variable to operations that require argument
 */
typedef struct state_s
{
	char *data_type;
	stack_t *head;
	stack_t *tail;
	char *argument;
} state_t;

extern state_t state; /* global variable to be used across functions */

#define INSTRUCTIONS \
		{ \
			{"push", _push}, \
			{"pall", _pall}, \
			{"pint", _pint}, \
			{"pop", _pop}, \
			{"swap", _swap}, \
			{"add", _add}, \
			{"nop", _nop}, \
			{"sub", _sub}, \
			{"div", _div}, \
			{"mul", _mul}, \
			{"mod", _mod}, \
			{"pchar", _pchar}, \
			{"pstr", _pstr}, \
			{"rotl", _rotl}, \
			{"rotr", _rotr}, \
			{"queue", _queue}, \
			{"stack", _stack}, \
			{NULL, NULL} \
		}

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/* utility functions */
int _nan(char *s); /* checks if a string sequence is not a valid number */
void free_stack(stack_t *stack); /* frees the stack */
void _queue(stack_t**, unsigned int); /* changes state.data_type to queue */
void _stack(stack_t**, unsigned int); /* changes state.data_type to stack */

#endif /* _MONTY_H_ */
