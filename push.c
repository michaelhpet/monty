#include "monty.h"

/**
 * _push - push node to stack (doubly-linked list)
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (argument == NULL || _nan(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(argument);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
