#include "monty.h"

/**
 * _push - Pushes an element to the stack.
 * @stack: Double pointer to the stack (__attribute__((unused))).
 * @line_number: Line number in the Monty bytecodes file.
 */
void _push(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
    stack_t *new_node;
    int value, j;

    if (!ah_sa.arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    for (j = 0; ah_sa.arg[j] != '\0'; j++)
    {
        if (!is_integer(&ah_sa.arg[j]))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            printf("%d\n", ah_sa.arg[j]);
            free_vglo();
            exit(EXIT_FAILURE);
        }
    }
    
    value = atoi(ah_sa.arg);
    
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
