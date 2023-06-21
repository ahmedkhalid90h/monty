#include "monty.h"





#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			return instruct[i].f;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", ah_sa.cont, opc);
	exit(EXIT_FAILURE);
}





void free_vglo(void)
{
    if (ah_sa.head)
        free_dlistint(ah_sa.head);
    if (ah_sa.buffer)
        free(ah_sa.buffer);
}


void free_dlistint(stack_t *head)
{
    stack_t *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
