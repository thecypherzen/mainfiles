#include "gosh.h"
/**
 * _getparent_path - gets the absolute path to parent of a 
 * directory.
 * @cwd: abs path to current working directory
 * Return: path to parent directory on success, NULL on error,
 * failure or empty string.
 */
char *_getparent_path(char *cwd)
{
	int i, j, len = (int)strlen(cwd);
	char *parent = NULL;

	if (cwd)
	{
		i = len - 1;
		if (i < 0)
			return (parent);
		while (cwd[i] != '/')
		{
			i--;
			if (i < 0)
				return (parent);
		}
		if (!i && len == 1)
			return (parent);
		if (!i)
			parent = malloc(2), i = 1;
		else
			parent = malloc(i + 1);
		if (!parent)
			return (NULL);
		for (j = 0; j < i; j++)
			parent[j] = cwd[j];
		parent[j] = '\0';
	}
	return (parent);
}