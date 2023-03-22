#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	current = *stack;
	if (current == NULL || current->next == NULL)
		return;

	while (current)
	{
		if (current->next == NULL)
		{
			current->prev->next = NULL;
			break;
		}

		current = current->next;
	}

	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
