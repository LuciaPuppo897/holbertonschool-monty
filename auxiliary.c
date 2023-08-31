#include "monty.h"
/**
 * is_valid_num - Checks if a string is a valid integer
 * Return: 1 if valid, 0 if not
 * @str: String to check
 **/
int is_valid_num(char *str)
{
	char *temp = str;

	if (str == NULL)
		return (0);

	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if ((*temp < '0' || *temp > '9'))
		{
			return (0);
		}
	}

	return (1);
}


/**
 * free_stack - Frees a doubly linked list
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
