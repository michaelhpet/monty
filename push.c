#include "monty.h"

/**
 * _push - push node to stack (doubly-linked list)
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n = atoi(state.argument);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (state.argument == NULL || _nan(state.argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = n, new_node->next = NULL, new_node->prev = NULL;
	if (strcmp(state.data_type, "stack") == 0)
	{
		new_node->prev = NULL;
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
		state.head = *stack;
		if ((*stack)->next == NULL)
			state.tail = *stack;
		return;
	}
	if (*stack == NULL)
	{
		*stack = new_node, state.head = new_node, state.tail = new_node;
		return;
	}

	(state.tail)->next = new_node;
	new_node->next = NULL;
	new_node->prev = state.tail;
	state.tail = new_node;
}
