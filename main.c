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
		return status;
	}
	debut_shell();
	return 0;
}

/**
 * non_intermode - Executes shell commands in non_nteractive_mode
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

				handle_exit_status(my_status, sngl_cmd, &token, status);
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
			print_env_var();
			*status = 0;
		}
		else
			_execvep(sngl_cmd, environ, status);
	}
	free_array(sngl_cmd);
}

/**
 * splinter_string - Splits a string into tokens
 * @s: string
 * @delim: delimiters
 *
 * Return: result.
 */

char **splinter_string(char *s, char *delim)
{
	int i = 0;
	char *token;
	char **result = malloc(20 * sizeof(char *));

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (token = strtok(s, delim); token != NULL; i++, token = strtok(NULL, delim))
	{
		result[i] = _strdup(token);
	}

	for (; i < 20; i++)
	{
		result[i] = NULL;
	}

	return (result);
}
