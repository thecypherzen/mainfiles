#include "gosh.h"
/**
 * _getfpath_copier - copies a directory to fullpath array
 * @full_path: ptr to full_path array address
 * @name: ptr to director name
 * @strt: index of full_path at which to start writing
 * Return: next index of full_path to start writing
 */
int _getfpath_copier(char **full_path, char *name, int strt)
{
	int i, j;
	for (j = strt, i = strlen(name) - 1; i >= 0; i--, j++)
	{
		(*full_path)[j] = name[i];
	}
	(*full_path)[j++] = '/';
	(*full_path)[j] = '\0';
	if (j == 1024)
	{
		(*full_path) = realloc(*full_path, j + 512);
		if (!(*full_path))
			return (-1);
	}
	return (j);
}