#include "gosh.h"

int main(void)
{
	char *path = "/dir";
	char *full_path = getfull_path(path);
	if (full_path)
	{
		printf("full_path: %s\n", full_path);
		free(full_path);
	}
	else
		printf("invalid path\n");
	return (0);
}
