#include <stdlib.h>
#include "monty.h"

/**
 * _nan - checks if a string contains non-digit characters
 * @s: string to parse
 * Return: 0 if all chars are digits, 1 otherwise
*/
int _nan(char *s)
{
	int i = 0;

	while (*s)
	{
		if (*s == '-' && i == 0)
		{
			s++, i++;
			continue;
		}

		if (*s < 48 || *s > 57)
			return (1);
		s++, i++;
	}

	return (0);
}

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

