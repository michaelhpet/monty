#include "monty.h"

/**
 * _stack - sets the format of the data to a stack
 * @queue: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _stack(stack_t **queue, unsigned int line_number)
{
	(void)queue;
	(void)line_number;
	state.data_type = "stack";
}
