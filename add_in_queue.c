#include "monty.h"

/**
 * add_in_queue - add node to the tail stack or queue
 * @n: new_value to add
 * @h: head of the stack or queue
 * Return: no return
*/
void add_in_queue(my_stack_t **h, int n)
{
	my_stack_t *new_node_is, *aux_in;

	aux_in = *h;
	new_node_is = malloc(sizeof(my_stack_t));
	if (new_node_is == NULL)
	{
		printf("Error\n");
	}

	new_node_is->n = n;
	new_node_is->next = NULL;

	if (aux_in)
	{
		for ( ; aux_in->next != NULL; aux_in = aux_in->next)
		;
	}
	if (!aux_in)
	{
		*h = new_node_is;
		new_node_is->prev = NULL;
	}
	else
	{
		aux_in->next = new_node_is;
		new_node_is->prev = aux_in;
	}
}
