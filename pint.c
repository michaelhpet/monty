#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		return;
	}

	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
