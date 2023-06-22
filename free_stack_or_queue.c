#include "monty.h"

/**
* free_stack_or_queue - frees a doubly linked list and frees the file
* @h: head of the stack or queue
*/
void free_stack_or_queue(my_stack_t *h)
{
	my_stack_t *aux_free;

	aux_free = h;
	while (h)
	{
		aux_free = h->next;
		free(h);
		h = aux_free;
	}
}
/**
 * add_node_in_stack - add node to the head stack or queue
 * @h: head of the stack or queue
 * @n_v: new_value to add
 * Return: no return
*/
void add_node_in_stack(my_stack_t **h, int n_v)
{

	my_stack_t *new_node_in, *aux_is;

	aux_is = *h;
	new_node_in = malloc(sizeof(my_stack_t));
	if (new_node_in == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux_is)
	{
		aux_is->prev = new_node_in;
	}
	new_node_in->n = n_v;
	new_node_in->next = *h;
	new_node_in->prev = NULL;
	*h = new_node_in;
}
