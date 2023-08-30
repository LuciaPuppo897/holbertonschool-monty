#include "monty.h"

/**
 * swap - swap 2 most recent nodes on stack
 *
 * @h: head of stack
 * @ln: line number
 * Return: void
 */
void swap(stack_t **h, unsigned int ln)
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

}

/**
 * add - add top 2 nodes of stack
 *
 * @h: head of stack
 * @ln: line number
 * Return: void
 */
void add(stack_t **h, unsigned int ln)
{
	unsigned int sum;
	stack_t *temp;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		isFail = 1;
		return;
	}

	temp = (*h)->next;
	sum = (*h)->n + temp->n;
	temp->n = sum;
	pop(h, ln);
}

