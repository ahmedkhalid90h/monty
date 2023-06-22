#include "monty.h"

/**
 * _add_node - adds the top two elements of the stack or queue.
 * @he: stack head or queue head
 * @count: line_number of the file
 * Return: no return
*/
void _add_node(my_stack_t **he, unsigned int count)
{
	my_stack_t *h;
	int len = 0, aux_in_s;

	h = *he;
	for (len = 0; h != NULL; len++) {
		h = h->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(cat.file);
		free(cat.content);
		free_stack_or_queue(*he);
		exit(EXIT_FAILURE);
	}
	h = *he;
	aux_in_s = h->n + h->next->n;
	h->next->n = aux_in_s;
	*he = h->next;
	free(h);
}
