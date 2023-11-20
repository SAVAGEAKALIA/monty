#include "monty.h"
/**
 *dequeue - instruction to add node to stack
 *@stack: struct
 *@line_number: line number in file
 */

void dequeue(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;

	free(temp);
}

/**
 *enqueue - instruction to add node to stack
 *@stack: struct
 *@line_number: line number in file
 */
void enqueue(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \t\n");
	int value;
	stack_t *last = malloc(sizeof(stack_t));

	(void)line_number;

	if (last == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	last->n = value;
	last->next = NULL;
	last->prev = NULL;

	if (*stack == NULL)
	{
		*stack = last;
	}
	else
	{

		while ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
		}

		(*stack)->next = last;
		last->prev = *stack;
	}
}
