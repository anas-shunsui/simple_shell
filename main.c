#include "simple_shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @argv: arg vector
 *
 * Return: Exit status
 */
int main(int ac, char **argv)
{
	char *l = NULL, **cmd = NULL;
	int stat = 0;
	(void) ac;

	while (1)
	{
		l = read_line();
		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		cmd = splinter(l);
		if (!cmd)
			continue;

		stat = _exec(cmd, argv);
	}
}
