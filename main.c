#include "monty.h"

/**
 * main - a monty bytecode interpreter for working with stacks and queues
 * data structures
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
		vmonty(command, line_number);
	}

	fclose(file);
	return (0);
}
