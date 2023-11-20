#include "monty.h"
/**
 *push - instruction to add node to stack
 *@stack: struct
 *@line_number: line number in file
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *top;
	char *value_str = strtok(NULL, " \t\n");

	is_integer(value_str, line_number);

	value = atoi(value_str);

	top = createNode(value);
	top->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = top;
	}

	*stack  = top;
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
		err_txt2(2, line_number);
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
		err_txt2(1, line_number);
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
		err_txt(6, line_number);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
