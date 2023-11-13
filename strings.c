#include "simple_shell.h"

/**
 * _strdup - Duplicates a string
 * @src: The source string to duplicate
 *
 * Return: Returns a pointer(str)
 */
char *_strdup(const char *src)
{
	char *str;
	char *p;
	int len = 0;

	for (len = 0; src[len]; len++)
		;

	str = malloc(len + 1);
	if (!str)
		return (NULL);

	p = str;
	for (; *src;)
		*p++ = *src++;
	*p = '\0';
	return (str);
}

/**
 * _strlen - length of a string
 * @str: string
 *
 * Return: length of the string.
 */

int _strlen(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: The difference between the ASCII values of the first unmatched
 * characters, 0 if the strings are identical.
 */
int _strcmp(char *str1, char *str2)
{
	int a = 0;

	for (; str1[a] != '\0' && str2[a] != '\0'; a++)
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}
	}

	return (str1[a] - str2[a]);
}

/**
 * _atoi - convert a string into an integer.
 * @str: string
 *
 * Return: int
 */
int _atoi(char *str)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	for (; !(str[i] <= '9' && str[i] >= '0') && str[i] != '\0';)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	for (; str[i] <= '9' && (str[i] >= '0' && str[i] != '\0');)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}

	res *= sign;
	return (res);
}
