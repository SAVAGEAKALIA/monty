#include "monty.h"
/**
 *process_line - Tokenizes the input line and calls the corresponding
 *@line: The input line to be processed.
 *@line_number: The line number in the file
 *@stack: A pointer to the stack.
 */

void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode, *line_copy;
	instruction_t *instruction;

	line_copy = strdup(line);
	opcode = strtok(line_copy, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
	{
		free(line_copy);
		return;
	}

	instruction = find_instruction(opcode);
	if (instruction == NULL)
	{
		err_txt(3, line_number, opcode);
		free(line_copy);
	}

	instruction->f(stack, line_number);
	free(line_copy);
}

/**
 *find_instruction - Finds the corresponding instruction based on the opcode
 *@opcode: The opcode to search for.
 *Return: a pointer to the instruction structure if found, null otherwise
 */

instruction_t *find_instruction(const char *opcode)
{
	int i;

	static instruction_t instructions[] = {
	{"pall", pall},
	{"push", push},
	{"pop",  pop},
	{"pint", pint},
	{"swap", swap},
	{"add", add},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod},
	{"nop", nop},
    /* ... other opcodes ... */
	{NULL, NULL} /* This is a sentinel value to mark the end of the array */
};

	for (i = 0; instructions[i].opcode != NULL; i++)
{
	if (strcmp(instructions[i].opcode, opcode) == 0)
	{
		return (&instructions[i]);
	}
}
return (NULL);
}
