#include "monty.h"

/**
 * _mod - computes the rest of the division of the
 * second top element of the stack by the top element
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int n1, n2;
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		tmp = *stack;
		n1 = tmp->n;
		n2 = tmp->next->n;
		tmp->next->n = n2 % n1;
		tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
		return;
	}

	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
