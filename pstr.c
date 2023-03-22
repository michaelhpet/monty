#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *current;

	current = (*stack);
	while (current)
	{
		n = current->n;
		if (n && n <= 127)
		{
			fprintf(stdout, "%c", n);
		}
		current = current->next;
	}

	fprintf(stdout, "\n");
}
