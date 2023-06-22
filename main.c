#include "monty.h"

cat_t cat = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter and executor
* @argc: number of arguments and file name
* @argv: monty file location and name
* Return: 0 on success or EXIT_FAILURE on failure
*/

int main(int argc, char *argv[])
{
	ssize_t r_line_ = 1;
	size_t size = 0;
	unsigned int coun = 0;
	my_stack_t *stack = NULL;
	FILE *file_is_r;
	char *content_in_f;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_is_r = fopen(argv[1], "r");
	cat.file = file_is_r;
	if (!file_is_r)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (r_line_ > 0)
	{
		content_in_f = NULL;
		r_line_ = getline(&content_in_f, &size, file_is_r);

		cat.content = content_in_f;
		coun++;
		if (r_line_ > 0)
		{
			exe(content_in_f, &stack, coun, file_is_r);
		}
		free(content_in_f);
	}
	free_stack_or_queue(stack);
	fclose(file_is_r);
	return (0);
}
