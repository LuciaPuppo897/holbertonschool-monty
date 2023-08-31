#include "monty.h"
int value;
/**
 * _swap - swaps the twp top elements of the stack
 *	@stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 *
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *first = *stack;
	stack_t *second = (*stack)->next;
	stack_t *third = second->next;

	first->next = second->next;
	second->next = first;
	if (third)
		third->prev = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}


/**
 * _add - add the 2 top nodes of stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
{
	printf("L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

stack_t *node_1 = *stack;
stack_t *node_2 = (*stack)->next;

sum = node_1->n + node_2->n;
node_2->n = sum;

_pop(stack, line_number);
}

/**
 * _nop - doesn´t do anything
 *	@stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
