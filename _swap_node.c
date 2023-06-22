#include "monty.h"

/**
 * _swap_node - adds the top two elements of the stack or queue.
 * @he: stack head or queue head
 * @count: line_number of the file
 * Return: no return
*/
void _swap_node(my_stack_t **he, unsigned int count)
{
	my_stack_t *h;
	int j = 0, aux_i;

	h = *he;
	for (j = 0; h != NULL; j++)
	{
		h = h->next;
	}
	if (j < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(cat.file);
		free(cat.content);
		free_stack_or_queue(*he);
		exit(EXIT_FAILURE);
	}
	h = *he;
	aux_i = h->n;
	h->n = h->next->n;
	h->next->n = aux_i;
}
/**
  *s_nop- nothing to do
  *@h: stack head or queue head
  *@coun: line_number of the file
  *Return: no return
 */
void _nop_node(my_stack_t **h, unsigned int coun)
{
	(void) coun;
	(void) h;
}
