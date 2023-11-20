#include "monty.h"

/**
 *createNode - function to create node
 *@value: data to to be used
 *Return: return new node on success
 */

stack_t *createNode(int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for a new node\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return (newNode);
}
