#include "monty.h"

/**
 * new_Node - creates a new node
 * @n: data of the new node
 * Return: pointer to new node
 */
int value;
stack_t *new_Node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * _push - Pushes an element onto the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void _push(stack_t **stack, unsigned int line_number)
{

	stack_t *new = NULL;
	(void)line_number;
	new = new_Node(value);
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
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

	if (*stack == NULL)
	return;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint- prints the value at the top of the stack
 *@stack: Pointer to the top of the stack
 *@line_number: Line number in the file
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
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;

	*stack = (*stack)->next; /*points to the 2nd superior node*/
	free(temp);
}
