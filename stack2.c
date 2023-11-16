#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int sum;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = top->n + top->next->n;
	top->next->n = sum;

	/* Pop the top element */
	pop(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* nop does nothing */
}
