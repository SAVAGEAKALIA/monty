#include "monty.h"
/**
 *mod - remainder of top two elements of the stack
 *@stack: pointer to the stack
 *@line_number: line number in the file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int mod;

	if (top == NULL || top->next == NULL)
	{
		err_txt2(7, line_number);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = top->next->n % top->n;
	top->next->n = mod;

	pop(stack, line_number);
}

/**
 * pchar - Print the char at the top of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty file where the opcode is called
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		err_txt3(1, line_number);
	}

	if ((top->n < 65) || (top->n > 122))
	{
		err_txt3(2, line_number);
	}

	printf("%c\n", top->n);
}

/**
 *pstr - Print the string starting at the top of the stack
 *@stack: Double pointer to the beginning of the stack
 *@line_number: Line number in the Monty file
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		printf("\n");
		return;
	}

	while (top != NULL && top->next != NULL && top->n != 0)
	{
		if ((top->n < 65) || (top->n > 122))
		{
			return;
		}
		printf("%c", top->n);
		top = top->next;
	}

	printf("\n");
	(void)line_number;
}

/**
 * rotl - Rotate the stack to the top
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty file where the opcode is called
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *current = *stack;

	(void)line_number;

	if (top == NULL || top->next == NULL)
	{
		return;
	}

	while (top->next != NULL)
	{
		top = top->next;
	}

	top->next = current;
	current->prev = top;
	current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;

	*stack = current;
}


/**
 * rotr - Rotate the stack to the bottom
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty file where the opcode is called
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (temp->next != NULL)
		{
			current = temp;
			temp = temp->next;
		}

		current->next = NULL;
		temp->prev = NULL;

		temp->next = *stack;
		(*stack)->prev = temp;

		*stack = temp;
	}
}
