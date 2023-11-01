#include "gosh.h"
/**
 * getfull_path - gets the absolute path to a file or directory
 * specified by path.
 * @path: abasolute or relative path to file or directory
 * Return: ptr to full_path on success, NULL otherwise.
 */
char *getfull_path(char *path)
{
	char *full_path = NULL, *pwd_name = NULL, **vect;
	int i = 0, k = 0;

	full_path = malloc(1024);
	if (!full_path || !path)
		return (NULL);
	if (*path == '/')
	{
		strcpy(full_path, path);
		return (full_path);
	}
	vect = make_vectr(path, "/");
	if (!vect)
	{
		free(full_path);
		return (NULL);
	}
	for (i = 0; vect[i + 1]; i++)
		;
	if (!(vect[i]))
	{
		pwd_name = _getdir_name(path);
		if (strcmp(pwd_name, "/") == 0)
		{
			free_vectr(vect), free(full_path);
			return (pwd_name);
		}
	}
	else
		k = _fpath_maker(&full_path, vect, i);
	free_vectr(vect);
	if (k == -1)
	{
		free(full_path);
		return (NULL);
	}
	return (full_path = str_rev(full_path));
}