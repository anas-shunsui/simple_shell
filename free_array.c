#include "simple_shell.h"

/**
 * free_array - frees arrays
 * @array: array
 *
 * Return: nothing
*/

void free_array(char **array)
{
	int a;

	if (!array)
		return;

	for (a = 0; array[a]; a++)
	{
		free(array[a]);
		array[a] = NULL;
	}
	free(array);
	array = NULL;
}
