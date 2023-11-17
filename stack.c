#include "monty.h"
/**
 *push - instruction to add node to stack
 *@stack: struct
 *@line_number: line number in file
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *value_str = strtok(NULL, " \t\n");
	stack_t *top = malloc(sizeof(stack_t));

	if (value_str == NULL || !is_integer(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed, push\n");
		exit(EXIT_FAILURE);
	}
	value = atoi(value_str);

	top->n = value;
	top->next = *stack;

	if (*stack == NULL)
	{
		*stack = top;
	}

	*stack = top;
}

/**
 *pop - instruction to delete node to stack
 *@stack: struct
 *@line_number: line number in file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *temp = NULL;

	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->next == NULL)
	{
		free(top);
		*stack = NULL;
		return;
	}

	temp = top->next;
	temp->prev = NULL;
	(*stack) = temp;
	free(top);
}


/**
 *pall - print the elements in stack
 *@stack: stacks
 *@line_number: line number in file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *pint - print the top elements in stack
 *@stack: stacks
 *@line_number: line number in file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *print_top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", print_top->n);
}


/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int temp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
