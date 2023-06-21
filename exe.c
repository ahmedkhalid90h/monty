#include "monty.h"

/**
* exe - execute the monty code and check if the opcode is valid
* @stack: head linked list - stack and queue
* @count: line_counter and number to push
* @file_is_r: pointer to monty file to close
* @content_in_f: line content to free
* Return: no return and
*/
int exe(char *content_in_f, my_stack_t **stack, unsigned int count,
FILE *file_is_r)
{
	instruction_t op_linked_List[] = {
				{"pall", s_pall},
				{"push", _push_node},
				{"pint", s_pint},
				{"pop", s_pop},
				{"swap", s_swap},
				{"add", s_add},
				{"nop", s_nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op_cmp;

	op_cmp = strtok(content_in_f, " \n\t");
	if (op_cmp && op_cmp[0] == '#')
		return (0);

	cat.arg = strtok(NULL, " \n\t");
	while (op_linked_List[i].opcode && op_cmp)
	{
		if (strcmp(op_cmp, op_linked_List[i].opcode) == 0)
		{	op_linked_List[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op_cmp && op_linked_List[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op_cmp);
		fclose(file_is_r);
		free(content_in_f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}