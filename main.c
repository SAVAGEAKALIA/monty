#include "monty.h"
#include <stdio.h>
/**
 *main - main function for stacks and	Queues Project
 *@argc: argument count for file
 *@argv: arguments
 *Return: exit success on success else exit failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
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

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		process_line(line, line_number, &stack);
	}

	free(line);
	fclose(file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
