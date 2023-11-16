#include "monty.h"
/**
 *is_integer - function to check if string is digit
 *@str: string to be checked
 *Return: 1 on sucess
 */

int is_integer(const char *str)
{
	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 *free_stack - frees a stack
 *@stack: pointer to the top of the stack
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL && (*stack)->next)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
