#include "monty.h"

/**
 * _push_node - add node to the stack or queue
 * @h: stack head or queue head
 * @count: line_number to push
 * Return: no return
*/
void _push_node(my_stack_t **h, unsigned int count)
{
	int n, j = 0, err = 0;

	if (cat.arg)
	{
		if (cat.arg[0] == '-')
			j++;
		while (cat.arg[j] != '\0')
		{
			if (cat.arg[j] > 57 || cat.arg[j] < 48)
				err = 1;
			j++;
		}
		if (err == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(cat.file);
			free(cat.content);
			free_stack_or_queue(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(cat.file);
		free(cat.content);
		free_stack_or_queue(*h);
		exit(EXIT_FAILURE);
	}
	n = atoi(cat.arg);
	if (cat.lifi == 0)
		add_node_in_stack(h, n);
	else
		add_in_queue(h, n);
}
