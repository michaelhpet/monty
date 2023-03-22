#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _pchar(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", n);
}
