#include "simple_shell.h"

/**
 * read_line - reads line
 *
 * Return: 1 on success
*/

char *read_line(void)
{
	char *l = NULL;
	size_t length = 0;
	ssize_t num;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	num = getline(&l, &length, stdin);
	if (num == -1)
	{
		free(l);
		return (NULL);
	}
	return (l);
}
