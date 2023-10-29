#include "gosh.h"

/**
 * make_vectr: makes a vector from a string based usiing a delimiter
 * @inputstr: the string
 * @delim: the delimiting string
 * Return: ptr to the vecor on success.
 *         NULL otherwise or if error
 */
char **make_vectr(char *inputstr, char *delim)
{
	char **vectr, *str, *token;
	int n = 0, i;

	if (!inputstr)
		return (NULL);

	str = strdup(inputstr);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == *delim)
			n++;
	}
	n += 2;
	vectr = malloc(sizeof(char *) * (n));
	if (!vectr)
		return (NULL);
	vectr[--n] = NULL, token = strtok(str, delim);
	for (i = 0; token && i < n; i++)
	{
		vectr[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	free(str);
	return (vectr);
}