#include "monty.h"

/**
* free_stack - frees a doubly linked list and frees the file
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
