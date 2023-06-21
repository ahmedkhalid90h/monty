#include "monty.h"

/**
 * _pall - Prints all the values on the stack, starting from the top of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty bytecodes file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


void _pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}   



/**
 * _pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecodes file.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
