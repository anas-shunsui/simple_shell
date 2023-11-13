#include "simple_shell.h"

/**
 * _exec - Execute shell commands
 * @cmds: Commands
 * @environ: The environment
 * @status: The pointer to an int where the status will be stored
 */

void _exec(char **cmds, char **environ, int *status)
{
	char *path = NULL;
	int pid;

	if (access(cmds[0], X_OK) == 0)
	{
		pid = fork();

		if (pid == 0)
			execve(cmds[0], cmds, environ);
		else
			wait_child_process(status);
	}
	else if (search_path(cmds[0], &path))
	{
		pid = fork();

		if (pid == 0)
			execve(path, cmds, environ);
		else
			wait_child_process(status);

		free(path);
	}
	else
	{
		*status = 127;
		write_error(cmds[0]);
	}
}

/**
 * _search - Searches the full path
 * @cmd: Command
 * @path: path
 *
 * Return: void
 */

int _search(char *cmd, char **path)
{
	char *token, *env;
	int path_found = 0;

	env = mygetenv("PATH");

	if (env != NULL)
	{
		char *path_env_copy = strdup(env);

		for (token = strtok(path_env_copy, ":"); token != NULL && !path_found; token = strtok(NULL, ":"))
		{
			*path = malloc(strlen(token) + strlen(cmd) + 2);
			if (*path != NULL)
			{
				strcpy(*path, token);
				strcat(*path, "/");
				strcat(*path, cmd);
				if (access(*path, X_OK) == 0)
				{
					path_found = 1;
				}

				if (!path_found)
					free(*path);
			}
		}

		free(path_env_copy);
	}

	return path_found;
}

/**
 * child_process - Waits for a child process
 * @status: the exit status
 *
 * Return: void
 */

void child_process(int *status)
{
	int stat;

	for (; wait(&stat) == -1;)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(stat))
	{
		*status = WEXITSTATUS(stat);
	}
}

/**
 * _getenv - Searches for an environment variable
 * @path: path
 *
 * Return: NULL if not found
 */

char *_getenv(const char *path)
{
	int a;
	int lengthOf_path = _strlen((char *)path);

	for (a = 0; environ[a] != NULL; a++)
	{
		if (!strncmp(path, environ[a], lengthOf_path))
		{
			if (environ[a][lengthOf_path] == '=')
			{
				return (environ[a] + lengthOf_path + 1);
			}
		}
	}

	return (NULL);
}

/**
 * _environ_var - Prints the environment variables to stdout
 *
 * Return: void
 */

void _environ_var(void)
{
	char **env = environ;

	for (; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}
