#include "monty.h"
/*contains the function to excecute*/
instruction_t instructions[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"add", _add},
	{"nop", _nop},

};

/**
 *main - recives arguments and excecute a specfic function
 *@argc : number of args
 *@argv : the arguments
 *Return: 0 if success 1 otherwise
*/
int main(int argc, char *argv[])
{
	(void)argc;

		FILE *inputFile = fopen(argv[1], "r");
	if (!inputFile) /*in case of error */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char line[100];
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), inputFile))
	{
		char *opcode = strtok(line, " \n");
		/*tokenize the input*/
		if (!opcode)
		{
			continue;

		int num_instructions = sizeof(instructions) / sizeof(instruction_t);

		for (int i = 0; i < num_instructions; i++) /*recorre la estructura*/
		{
			if (strcmp(opcode, instructions[i].opcode) == 0) /*check a coincidence*/
			{
				instructions[i].f(&stack, line_number); /*calls the structure*/
				break;
			}
		}

		line_number++;
	}

	fclose(inputFile);
	return (0);
}
}
