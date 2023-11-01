#include "gosh.h"

/**
 * _fpath_maker - constructs the full_path from vector members
 * @full_path: ptr to full_path address
 * @vect: vector members of user provided path
 * @i: index of vector to start reading at
 * Return: 0 on success, 1 otherwise
 */
int _fpath_maker(char **full_path, char **vect, int i)
{
	char *temp = NULL, *pwd_name = NULL, *pwd = NULL;
	int k = 0;

	for (; i >= 0; i--)
	{
		k = _getfpath_helpr(full_path, &pwd, vect[i]);
		if (k < 0)
		{
			free(full_path), free_vectr(vect);
			return (1);
		} 
	}
	if (!pwd)
		pwd = getcwd(NULL, 0);
	while (strcmp(pwd, "/") != 0)
	{
		pwd_name = _getdir_name(pwd);
		k = _getfpath_copier(full_path, pwd_name, k);
		temp = pwd, pwd = _getparent_path(pwd);
		free(pwd_name);
		if (temp)
			free(temp), temp = NULL;
	}
	if (pwd)
		free(pwd);
	return (0);
}

