#include "simple_shell.h"

/**
 * _debut - shell's main
 *
 * Description: handle user input
 */

void _debut(void)
{
	char *l = NULL, **cmds, *environ[] = {NULL};
	size_t sizeof_l = 0;
	ssize_t reads;
	int stat = 0;

	while (1)
	{
		reads = read_cmd(&l, &sizeof_l);
		if (reads == -1)
			_getline_error(l);
		cmds = splinter_string(l, " \n\t");
		if (cmds[0])
		{
			if (!_strcmp(cmds[0], "exit"))
			{
				if (cmds[1])
				{
					int my_status = _atoi(cmds[1]);

					_custom_exit(my_status, cmds, l, &stat);
				}
				else
				{
					free(l);
					free_array(cmds);
					exit(stat);
				}
			}
			else if (!_strcmp(cmds[0], "env"))
			{
				_environ_var();
				stat = 0;
			}
			else
				_exec(cmds, environ, &stat);
		}
		free_array(cmds);
		free(l);
		l = NULL;
	}
}


/**
 * read_cmd - Reads a line of command from the user
 * @l: The line buffer to store command
 * @sizeof_l: The size of the line buffer
 *
 * Return: Returns the number of characters read.
 */
ssize_t read_cmd(char **l, size_t *sizeof_l)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(l, sizeof_l, stdin));
}
/**
 * _werror - Writes an error message to STDERR
 *
 * @cmd: command
 * Description: Writes an error message
 */
void _werror(char *cmd)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * _wexit_werror - error message to STDERR
 *
 * @num: number
 * Description: Writes an error message
 */

void _wexit_werror(char *num)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * free_array - Frees memory
 * @array: Allocated array of strings.
 *
 * Return: Nothing
 */
void free_array(char **array)
{
	int count = 0;

	if (!array)
		return;

	while (array[count] != NULL)
	{
		free(array[count]);
		count++;
	}

	free(array);
}
