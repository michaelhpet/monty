#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *current, *first;

	first = *stack;
	current = *stack;

	if (current == NULL || current->next == NULL)
		return;

	while(current)
	{
		if (current->next == NULL)
			break;
		current = current->next;
	}

	current->next = first;
	first->prev = current;
	first->next = NULL;
	pop(stack, line_number);
}
