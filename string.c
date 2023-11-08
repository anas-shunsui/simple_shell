#include "simple_shell.h"

/**
 * _strdup - duplicate string
 * @s: string
 *
 * Return: character
*/

char *_strdup(const char *s)
{
	char *p;
	int a, length = 0;

	if (s == NULL)
		return (NULL);

	while (*s != '\0')
	{
		length++;
		s++;
	}
	s = s - length;
	p = malloc(sizeof(char) * (length + 1));
	if (p == NULL)
		return (NULL);
	for (a = 0; a <= length; a++)
		p[a] = s[a];
	return (p);
}

/*
*int _string_compare(char *str1, char str2)
*{
*
*}
*int _string_length(char *str);
*char *_string_cat(char *dest, char *src);
*char *_string_copy(char *dest, char *src);
*/
