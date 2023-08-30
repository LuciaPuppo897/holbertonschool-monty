#include "monty.h"
/**
 * _push - Pushes an element onto the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");

	if (!value_str)
	{
		printf("L%d: usage: push integer\n", line_number);
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
/*le asigna el nuevo puntero al prev */
	*stack = new_node;
}

/**
 * _pall - Prints all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void _pall(stack_t **stack, unsigned int line_number)
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
 * _pint- prints the value at the top of the stack
 *@stack: Pointer to the top of the stack.
 *@line_number: Line number in the file.
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL) /*only needs to print the stack*/
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * _pop - deletes the top element of the stack
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;

	*stack = (*stack)->next; /*points to the 2nd superior node*/
	free(temp);
}
