#include "gosh.h"
/**
 * _getdir_name - gets the name of the current working directory
 * from its abs path.
 * @cwd: absolute path to current working directory
 * Return: the name of the directory on success. NULL otherwise
 */
char *_getdir_name(char *cwd)
{
	int i, len, sz, j;
	char *dirname = NULL;

	if (cwd)
	{
		len = (int)strlen(cwd), i = len - 1;
		if (i < 0)
			return (dirname);
		while (cwd[i] != '/')
		{
			i--;
			if (i < 0)
				break;
		}
		sz = i >= 0 && len > 1 ? len - i : len + 1;
		dirname = malloc(sz);
		if (!dirname)
			return (NULL);
		i = i >= 0 && len > 1 ? i + 1 : 0;
		for (j = 0; i < len; i++, j++)
			dirname[j] = cwd[i];
		dirname[j] = '\0';
	}
	return (dirname);
}