#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: pointer to head node
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	if (current == NULL)
		return;

	while (current->next)
	{
		current = current->next;
		free(current->prev);
	}

	if (current)
		free(current);
}
