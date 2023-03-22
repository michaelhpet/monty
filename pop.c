#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *to_free;

	if (*stack)
	{
		to_free = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(to_free);
		return;
	}

	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
