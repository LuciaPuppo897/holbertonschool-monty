#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");

	if (!value_str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(value_str);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}
/**
 * main - check if works
 * Return:0 if success
*/
int main(void)
{
	FILE *inputFile = fopen("input.txt", "r");

	if (!inputFile)
	{
		printf("L4: usage: push integer");
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char opcode[10];
	unsigned int line_number = 1;

	while (fgets(opcode, sizeof(opcode), inputFile))
	{
		strtok(opcode, " \n");

		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
			fclose(inputFile);
			return (EXIT_FAILURE);
		}

		line_number++;
	}

	fclose(inputFile);
	return (0);
}
