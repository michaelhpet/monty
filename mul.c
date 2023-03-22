#include "monty.h"

/**
 * _mul - multiplies the top two elements of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int n1, n2;
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		n1 = tmp->n;
		n2 = tmp->next->n;
		tmp->next->n = n2 * n1;
		tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
		return;
	}

	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
