#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		n = tmp->n;
		tmp->n = tmp->next->n;
		tmp->next->n = n;
		return;
	}

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
