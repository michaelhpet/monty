#include "monty.h"

/**
 * _sub -  subtracts the top element of the stack from the second top
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int n1, n2;
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		n1 = tmp->n;
		n2 = tmp->next->n;
		tmp->next->n = n2 - n1;
		tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
		return;
	}

	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
