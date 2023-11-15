#include "simple_shell.h"

/**
 * main - Entry point
 *
 * Return: Returns 0 on success
 */

int main(void)
{
	size_t sizeOf_line = 0;
	char *l = NULL;
	int status = 0;

	if (!isatty(0))
	{
		for (; getline(&l, &sizeOf_line, stdin) != -1;)
		{
			non_intermode(l, &status);
		}
		if (l)
		{
			free(l);
			l = NULL;
		}
		return (status);
	}
	_debut();
	return (0);
}

/**
 * non_intermode - Executes shell commands
 * @token: string
 * @status: integer
 *
 * Return: status
 */

void non_intermode(char *token, int *status)
{
	char **sngl_cmd;
	char *environ[] = {NULL};

	token[strlen(token) - 1] = '\0';
	sngl_cmd = splinter_string(token, " \t");
	if (sngl_cmd[0])
	{
		if (!_strcmp(sngl_cmd[0], "exit"))
		{
			if (sngl_cmd[1])
			{
				int my_status = _atoi(sngl_cmd[1]);

				_exit_status(my_status, sngl_cmd, &token, status);
			}
			else
			{
				free(token);
				free_array(sngl_cmd);
				exit(*status);
			}
		}
		else if (!_strcmp(sngl_cmd[0], "env"))
		{
			_environ_var();
			*status = 0;
		}
		else
			_exec(sngl_cmd, environ, status);
	}
	free_array(sngl_cmd);
}

/**
 * splinter_string - Splits a string into tokens
 * @s: string
 * @del: delimiters
 *
 * Return: result.
 */

char **splinter_string(char *s, char *del)
{
	int i = 0;
	char *split;
	char **res = malloc(20 * sizeof(char *));

	if (res == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (split = strtok(s, del); split != NULL; i++, split = strtok(NULL, del))
	{
		res[i] = _strdup(split);
	}

	for (; i < 20; i++)
	{
		res[i] = NULL;
	}

	return (res);
}
