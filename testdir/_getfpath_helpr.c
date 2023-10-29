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

	printf("\n**** inside gfp helpr ****\n");
	for (j = 0; chars[j]; j++)
		if (strcmp(vecti, chars[j]) == 0)
			break;
	if (chars[j] == NULL)
		k = _getfpath_copier(full_path, vecti, k);
	else
	{
		printf("exec entry\n");
		*pwd = *pwd ? *pwd : getcwd(NULL, 0);
		if (strcmp(chars[j], "..") == 0)
		{
			temp = *pwd, *pwd = _getparent_path(*pwd);
			printf("gfph: parent path: %s\n", *pwd ? *pwd
				: "null");
			if (temp)
			{
				printf("gfph:psec: freeing temp\n");
				free(temp), temp = NULL;
				printf("gfph:psec: freeing successful\n");
			}
			if (!(*pwd))
				return (-1);
		}
		else 
		{
			printf("in section 2\n");
			temp = *pwd;
			printf("pwd saved in temp\n");
			*pwd = (strcmp(chars[j], "~") == 0) ?
				strdup(getenv("HOME")) : *pwd;
			if (*pwd)
			{
				pwd_name = _getdir_name(*pwd);
				k = _getfpath_copier(full_path, 
					pwd_name, k);
				if (pwd_name)
				{
					printf("gfph: freeing pwd_name\n");
					free(pwd_name), pwd_name = NULL;
					printf("gfph: free successful\n");
				}
			}
			if (temp)
			{
				printf("gfph: freeing temp\n");
				free(temp), temp = NULL;
				printf("gfph: temp free successful\n");
			}
			/*printf("\n\nsaving pwd in temp again\n");
			printf("pwd: %s\n", *pwd ? *pwd : "null");
			temp = *pwd,  *pwd = _getparent_path(*pwd);
			printf("save successful\n");
			if (temp)
			{
				printf("gfph: freeing temp again\n");
				free(temp), temp = NULL;
				printf("gfph: free successful\n");
			}*/
		}
	}
	return (k);
}