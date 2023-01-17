#include "monty.h"

/**
 * main - a monty interpreter for working with stacks and queues
 * data structures
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 (success), non-zero on error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	printf("Welcome to Stacks and Queues\n");
	printf("File to parse: %s\n", argv[1]);
	printf("Work in progress...\n");

	return (0);
}
