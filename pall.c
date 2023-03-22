#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void pall(stack_t **stack, unsigned int line_number UNUSED)
{
	stack_t *current = *stack;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
