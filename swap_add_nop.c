#include "monty.h"

/*
 * _swap - swap 2 most recent nodes on stack
*@stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
*/

/*
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int x;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		isFail = 1;
		return;
	}
	temp = (*h)->next;
	x = (*h)->n;
	(*h)->n = temp->n;
	temp->n = x;

} */

/**
 * _add - add the 2 top nodes of stack
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL) /*if less than 2*/
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number); /*delete the top node*/
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
