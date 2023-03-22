#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last, *top;

	last = *stack;

	if (last == NULL || last->next == NULL)
		return;

	while (last)
	{
		if (last->next == NULL)
			break;
		last = last->next;
	}

	top = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}
