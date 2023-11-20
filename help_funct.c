#include "monty.h"
/**
 *is_integer - function to check if string is digit
 *@str: string to be checked
 *@line_number: line number from file
 *Return: 1 on sucess
 */

void is_integer(const char *str, unsigned int line_number)
{
	int i = 0;

	if (str == NULL || *str == '\0')
	{
		err_txt(5, line_number);
	}

	if (*str == '-' || *str == '+')
	{
		str++;
	}

	while (str[i] != '\0')
	{
		if (isdigit(str[i]) == 0)
		{
			err_txt(5, line_number);
		}
		i++;
	}
}

/**
 *free_stack - frees a stack
 *@stack: pointer to the top of the stack
 */

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}

	*stack = NULL;
}
