#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void add(stack_t **stack, unsigned int line_number)
{
	int n1, n2;
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		n1 = tmp->n;
		n2 = tmp->next->n;
		tmp->next->n = n1 + n2;
		tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
		return;
	}

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
