#include "gosh.h"
/**
 * _getfpath_helpr - helps getfull_path func to construct
 * the full path to a file/directory based on user-specified
 * path
 * @full_path: ptr to full_path address
 * @pwd: ptr to present working directory address
 * @vecti: current string in path, delimited by /, e.g
 * .. in ../../.
 * Return: next index in path to start writing on next iteration.
 */
int _getfpath_helpr(char **full_path, char **pwd, char *vecti)
{
	char *chars[] = {".", "..", "~", NULL}, *pwd_name = NULL,
	*temp = NULL;
	static int j, k = 0;

	for (j = 0; chars[j]; j++)
		if (strcmp(vecti, chars[j]) == 0)
			break;
	if (chars[j] == NULL)
		k = _getfpath_copier(full_path, vecti, k);
	else
	{
		*pwd = *pwd ? *pwd : getcwd(NULL, 0);
		if (strcmp(chars[j], "..") == 0)
		{
			temp = *pwd, *pwd = _getparent_path(*pwd);
			free_charptr(&temp);
			if (!(*pwd))
				return (-1);
		}
		else 
		{
			if (strcmp(chars[j], "~") == 0)
			{
				temp = *pwd, *pwd = strdup(getenv("HOME"));
				free_charptr(&temp);
			}
			if (*pwd)
			{
				pwd_name = _getdir_name(*pwd);
				k = _getfpath_copier(full_path, 
					pwd_name, k);
				free_charptr(&pwd_name);
			}
			temp = *pwd,  *pwd = _getparent_path(*pwd);
			free_charptr(&temp);
		}
	}
	return (k);
}
