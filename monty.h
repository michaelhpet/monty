#ifndef _MONTY_H_
#define _MONTY_H_

#define INSTRUCTIONS \
		{ \
			{"push", _push}, \
			{"pall", _pall}, \
			{"pint", _pint}, \
			{"pop", _pop}, \
			{"swap", _swap}, \
			{"add", _add}, \
			{"nop", _nop}, \
			{NULL, NULL} \
		}

extern char *argument; /* argument variable to operations that require argument */

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

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/* utility functions */
int _nan(char *s); /* checks if a string sequence is not a valid number */
void free_stack(stack_t *stack); /* frees the stack */

#endif /* _MONTY_H_ */
