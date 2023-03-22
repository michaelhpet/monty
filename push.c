#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _push - push node to stack (doubly-linked list)
 * @stack: pdouble pointer to head node
 * @line_number: line number of file where instruction was parsed
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (op_arg == NULL || _nan(op_arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(op_arg);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
