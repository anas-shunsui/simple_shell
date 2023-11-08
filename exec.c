#include "simple_shell.h"

/**
 * _exec - execute command
 * @cmd: command
 * @argv: argument vector
 *
 * Return: status
*/

int _exec(char **cmd, char **argv)
{
	pid_t ch;
	int stat;

	ch = fork();
	if (ch == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free_array(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(ch, &stat, 0);
		free_array(cmd);
	}
	return (WEXITSTATUS(stat));
}
