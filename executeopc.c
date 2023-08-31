#include "monty.h"
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

