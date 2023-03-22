#include "monty.h"

/**
 * _nop - doesn’t do anything
 * @stack: double pointer to head node
 * @line_number: line number of file where instruction was parsed
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
