#include "simple_shell.h"

/**
 * splinter - Tokenizes the input line
 * @line: The input line
 *
 * Return: Array of tokens
 */
char **splinter(char *line)
{
	char *tok = NULL;
	char **cmd = NULL;
	int num_tokens = 0, a = 0;

	if (!line)
		return NULL;

	tok = strtok(line, DELIM);
	while (tok)
	{
		num_tokens++;
		tok = strtok(NULL, DELIM);
	}

	cmd = malloc(sizeof(char *) * (num_tokens + 1));
	if (!cmd)
		return NULL;

	tok = strtok(line, DELIM);
	while (tok)
	{
		cmd[a] = _strdup(tok);
		if (cmd[a] == NULL)
		{
			free_array(cmd);
			return NULL;
		}
		tok = strtok(NULL, DELIM);
		a++;
	}
	cmd[a] = NULL;

	return cmd;
}
