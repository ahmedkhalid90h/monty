#include "monty.h"

/**
 * _pint_node - prints the top node
 * @h: stack head or queue head
 * @count: line_number to push
 * Return: no return
*/
void _pint_node(my_stack_t **h, unsigned int count)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(cat.file);
		free(cat.content);
		free_stack_or_queue(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
/**
 * _pop_node - prints the top node
 * @he: stack head or queue head
 * @count: line_number to push
 * Return: no return
*/
void _pop_node(my_stack_t **he, unsigned int count)
{
	my_stack_t *h;

	if (*he == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(cat.file);
		free(cat.content);
		free_stack_or_queue(*he);
		exit(EXIT_FAILURE);
	}
	h = *he;
	*he = h->next;
	free(h);
}
