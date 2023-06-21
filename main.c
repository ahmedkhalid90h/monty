#include "monty.h"

global_m ah_sa; /* Define the global variable*/

void start_ah_sa(FILE *fd)
{
    ah_sa.lifo = 1;
    ah_sa.cont = 1;
    ah_sa.arg = NULL;
    ah_sa.head = NULL;
    ah_sa.fd = fd;
    ah_sa.buffer = NULL;
}

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    start_ah_sa(file); /* Initialize ah_sa*/

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        ah_sa.cont = line_number;
        ah_sa.arg = _strtoky(line, " \t\n");
        if (ah_sa.arg && ah_sa.arg[0] != '#')
        {
            
            void (*op_func)(stack_t **, unsigned int) = get_opcodes(ah_sa.arg);
            if (!op_func)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, ah_sa.arg);
                free(line);
                free_vglo();
                fclose(file);
                return EXIT_FAILURE;
            }
            op_func(&(ah_sa.head), line_number);
        }
    }

    free(line);
    free_vglo();
    fclose(file);
    return EXIT_SUCCESS;
}
