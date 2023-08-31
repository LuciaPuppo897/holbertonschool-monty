#include "monty.h"

/**
 * get_tokens - tokenize the data
 * line: buff
 * Return: a struct
*/
opcode_data get_tokens(char *line)
{
	opcode_data op_data;

	/*tokenize*/
	char *opcode = strtok(line, " \n\t\r");
	char *data = strtok(NULL, " \n\t\r");

	op_data.opcode = opcode;
	op_data.data = data;

	return op_data;
}
/**
 * execute_opcode - Executes the opcode based on the command
 * @opcode: Opcode command
 * @stack: Pointer to the top of the stack
 * @data: Data value
 * @line_number: Line number in the file
 * Return: 0 if successful, 1 if push error, 2 if unknown instruction
 */
int execute_opcode(char *opcode, stack_t **stack, char *data, int line_number)
{
    int i = 0;
    instruction_t op[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"nop", _nop},
        {NULL, NULL}
    };

    while (op[i].opcode)
    {
        if (!strcmp(opcode, op[i].opcode))
        {
            if (!strcmp(opcode, "push"))
            {
                if (is_valid_num(data) == 1)
                    value = atoi(data);
                else
                    return (1);
            }
            op[i].f(stack, line_number);
            return (0);
        }
        i++;
    }

    return (2);
}



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
	if (*stack == NULL || stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;

	*stack = (*stack)->next; /*points to the 2nd superior node*/
	free(temp);
}
#include "monty.h"
/**
 * _swap. swaps the twp top elements of the stack
 *	@stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
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
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
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

/**
 * is_valid_num - Checks if a string is a valid integer
 * Return: 1 if valid, 0 if not
 * @str: String to check
 **/
int is_valid_num(char *str)
{
	char *temp = str;
	
	if (str == NULL)
		return 0;
	
	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if ((*temp < '0' || *temp > '9'))
		{
			return 0;
		}
	}
	
	return 1;
}

#include "monty.h"

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

int value;

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Pointers to arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 1;

    while (getline(&line, &len, file) != -1)
    {
        opcode_data op_data = get_tokens(line);
        char *arguments = op_data.opcode;
        char *data = op_data.data;

        if (arguments != NULL)
        {
            int result = execute_opcode(arguments, &stack, data, line_number);
            if (result == 1)
            {
                dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
            else if (result == 2)
            {
                dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, arguments);
                free(line);
                fclose(file);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
        }

        line_number++;
    }

    free(line);
    fclose(file);
    free_stack(&stack);

    return (EXIT_SUCCESS);
}
