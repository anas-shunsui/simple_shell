#include "simple_shell.h"

/**
 * _exit_status - Handles exit status
 * @my_stat: The status to check.
 * @sngl_cmd: The command arguments.
 * @token: Token.
 * @status: status
 *
 * Return: void.
 */

void _exit_status(int my_stat, char **sngl_cmd, char **token,
											int *status)
{
	if (my_stat == -1 ||
		(my_stat == 0 && sngl_cmd[1][0] != '0') ||
		my_stat < 0)
	{
		_wexit_werror(sngl_cmd[1]);
		*status = 2;
	}
	else
	{
		free(*token);
		free_array(sngl_cmd);
		exit(my_stat);
	}
}

/**
 * _custom_exit - Handles custom exit statuses
 * @my_stat: The exit status
 * @cmds: command and its arguments.
 * @l: the input line.
 * @status: the return status value.
 *
 * Return: void.
 */

void _custom_exit(int my_stat, char **cmds,
						char *l, int *status)
{
	if (my_stat == -1 ||
		(my_stat == 0 && cmds[1][0] != '0') ||
		my_stat < 0)
	{
		write_exit_error(cmds[1]);
		*status = 2;
	}
	else
	{
		free(l);
		free_array(cmds);
		exit(my_stat);
	}
}
/**
 * _getline_error - Handles getline error.
 * @l: the input line.
 *
 * Return: void.
 */
void _getline_error(char *l)
{
	perror("getline");
	free(l);
	l = NULL;
	exit(EXIT_FAILURE);
}
