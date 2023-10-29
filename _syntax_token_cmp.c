#include "gosh.h"
/**
 * _syntax_token_cmp - compares a token with a string element
 * of a vector.
 * @lops: vector of strings
 * @token: the token
 * Return: 0 if not matched, 1 otherwise
 */
int _syntax_token_cmp(char **lops, char *token)
{
	int i, matched = 0;

	for (matched = 0, i = 0; lops[i]; i++)
	{
		if (strcmp(token, lops[i]) == 0)
		{
			matched = 1;
			break;
		}
	}
	return (matched);
}