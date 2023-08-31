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