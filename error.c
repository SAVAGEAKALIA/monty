#include "monty.h"
/**
 *err_txt - function to print error txt to stderr
 *@error_code: error case number to select switch case
 */

void err_txt(int error_code, ...)
{
	char *opcode;
	int num;

	va_list args;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			num = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 6:
			fprintf(stderr, "L%u: can't swap, stack too short\n", va_arg(args,
						int));
			break;
		default:
			break;
	}
	va_end(args);
	exit(EXIT_FAILURE);
}


/**
 *err_txt2 - function to print error txt to stderr
 *@error_code: error case number to select switch case
 */

void err_txt2(int error_code, ...)
{	int num;

	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't pint, stack empty\n", num);
			break;
		case 2:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't pop an empty stack\n", num);
			break;
		case 3:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't add, stack too short\n", num);
			break;
		case 4:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't sub, stack too short\n", num);
			break;
		case 5:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't div, stack too short\n", num);
			break;
		case 6:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't mul, stack too short\n", num);
			break;
		case 7:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't mod, stack too short\n", num);
			break;
		default:
			break;
	}
	va_end(args);
	exit(EXIT_FAILURE);
}

/**
 *err_txt3 - function to print error txt to stderr
 *@error_code: error case number to select switch case
 */

void err_txt3(int error_code, ...)
{
	int num;
	/*char *opcode;*/

	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't pchar, stack empty\n", num);
			break;
		case 2:
			num = va_arg(args, int);
			fprintf(stderr, "L%u: can't pchar, value out of range\n", num);
			break;
		default:
			break;
	}
	va_end(args);
	exit(EXIT_FAILURE);
}
