#include "gosh.h"
/**
 * getfull_path - gets the absolute path to a file or directory
 * specified by path.
 * @path: abasolute or relative path to file or directory
 * Return: ptr to full_path on success, NULL otherwise.
 */
char *getfull_path(char *path)
{
	char *full_path = NULL, *pwd = NULL, *pwd_name = NULL, 
	*temp = NULL, **vect;
	int i = 0, j = 0, k = 0;

	full_path = malloc(1024);
	if (!full_path || !path)
		return (NULL);
	if (*path == '/')
	{
		strcpy(full_path, path);
		return (full_path);
	}
	printf("making vectr\n");
	vect = make_vectr(path, "/");
	printf("vectr make successful\n");
	if (!vect)
	{
		free(full_path);
		return (NULL);
	}
	printf("preparing to check vect args\n");
	for (i = 0; vect[i + 1]; i++)
	{
		printf("vect[%d] = %s\n", i, vect[i] ? 
			vect[i] : "null");
	}
	printf("value of i: %d\n", i);
	if (!(vect[i]))
	{
		printf("vectr[i] is null\n");
		pwd_name = _getdir_name(path);
		if (strcmp(pwd_name, "/") == 0)
		{
			free_vectr(vect), free(full_path);
			return (pwd_name);
		}
	}
	else
	{
		printf("preparing to pass vectr args\n");
		for (; i >= 0; i--)
		{
			printf("\npassing %s to gfph\n", vect[i]);
			k = _getfpath_helpr(&full_path, &pwd, vect[i]);
			if (k < 0)
			{
				free(full_path), free_vectr(vect);
				return (NULL);
			}
		}
		printf("about to terminate\n");
		printf("pwd: %s\n", pwd ? pwd :"(null)");
		while (strcmp(pwd, "/") != 0)
		{
			printf("reading pwd_name\n");
			pwd_name = _getdir_name(pwd);
			printf("sending %s to copier\n", pwd_name);
			k = _getfpath_copier(&full_path, pwd_name, k);
			printf("copy successful. k = %d\n", k);
			temp = pwd, pwd = _getparent_path(pwd);
			printf("gfp: freeing pwd_name\n");
			free(pwd_name);
			printf("gfp: free successful\n");
			if (temp)
			{
				printf("gfp: freeing temp\n");
				free(temp);
				printf("gfp: free successful\n");
			}
		}
	}
	printf("gfp: freeing vectr\n");
	free_vectr(vect);
	printf("gfp: vectr free successful\n");
	if (pwd)
	{
		printf("gfp: freeing pwd\n");
		free(pwd);
		printf("grp: free successful\n");
	}
	return(full_path = str_rev(full_path));
}