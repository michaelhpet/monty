#include "monty.h"

/**
 * _queue - sets the format of the data to a queue
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	state.data_type = "queue";
}
