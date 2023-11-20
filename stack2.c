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
		err_txt2(3, line_number);
	}

	sum = top->n + top->next->n;
	top->next->n = sum;

	/* Pop the top element */
	pop(stack, line_number);
}
/**
 *sub - subtract the top two elements of the stack
 *@stack: pointer to the stack
 *@line_number: line number in the file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int sub;

	if (top == NULL || top->next == NULL)
	{
		err_txt2(4, line_number);
	}

	sub = (top->next->n) - (top->n);
	top->next->n = sub;

	pop(stack, line_number);
}

/**
 *divide - divide the top two elements of the stack
 *@stack: pointer to the stack
 *@line_number: line number in the file
 */

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int div;

	if (top == NULL || top->next == NULL)
	{
		err_txt2(5, line_number);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = top->next->n / top->n;
	top->next->n = div;

	pop(stack, line_number);
}

/**
 *mul - multiply the top two elements of the stack
 *@stack: pointer to the stack
 *@line_number: line number in the file
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int mul;

	if (top == NULL || top->next == NULL)
	{
		err_txt2(6, line_number);
	}

	mul = top->n * top->next->n;
	top->next->n = mul;

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
	return;
	/* nop does nothing */
}
