#include "monty.h"

char *argument;

/**
 * main - entry point of monty bytecode interpreter
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 (success), non-zero on error
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *buffer, *command;
	size_t buffer_len;
	unsigned int line_number;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_number = 0, buffer = NULL, buffer_len = 0;
	while (getline(&buffer, &buffer_len, file) != -1)
	{
		line_number++;
		if (*buffer == 10) /* skip empty lines */
			continue;
		command = strtok(buffer, " \t\n");
		argument = strtok(NULL, " \t\n");
		if (command == NULL || *command == '#') /* skip comments */
			continue;
		monty(&stack, command, line_number);
	}

	if (buffer)
		free(buffer);
	free_stack(stack);

	fclose(file);
	return (0);
}

/**
 * monty - a monty bytecode interpreter for working with stacks and queues
 * @stack: pointer to stack
 * @command: command or opcode of instruction
 * @line_number: line number of instruction file
*/
void monty(stack_t **stack, char *command, unsigned int line_number)
{
	int i = 0;
	instruction_t instruction[] = INSTRUCTIONS;

	while (instruction[i].opcode)
	{
		if (strcmp(command, instruction[i].opcode) == 0)
		{
			instruction[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}
