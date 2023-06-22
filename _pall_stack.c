#include "monty.h"

/**
 * _pall_stack - prints the stack or queue
 * @head: stack head or queue head
 * @count: no used - line_number to push
 * Return: no return
*/
void _pall_stack(my_stack_t **head, unsigned int count)
{
	my_stack_t *h;
	(void)count;

	h = *head;

	if (!h)
	{
		return;
	}
	for ( ; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
	}
}
