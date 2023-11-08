#include "simple_shell.h"

/**
 * splinter - tokenizer
 * @l: line
 *
 * Return: command
*/

char **splinter(char *l)
{
	char *tok = NULL, *t = NULL;
	char **cmd = NULL;
	int i = 0, a = 0;

	if (!l)
		return (NULL);
	t = _strdup(l);

	tok = strtok(t, DELIM);
	if (tok == NULL)
	{
		free(l), l = NULL;
		free(t), t = NULL;
		return (NULL);
	}

	while (t)
	{
		i++;
		tok = strtok(NULL, DELIM);
	}
	free(t), t = NULL;

	cmd = malloc(sizeof(char *) * (i + 1));
	if (!cmd)
	{
		free(l), l = NULL;
		return (NULL);
	}

	tok = strtok(l, DELIM);
	while (tok)
	{
		cmd[a] = _strdup(tok);
		tok = strtok(NULL, DELIM);
		a++;
	}
	free(l), l = NULL;
	cmd[a] = NULL;
	return (cmd);
}
