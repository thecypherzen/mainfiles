#include "gosh.h"

/* /home/runner/NewC/mainfiles/testdir */
/* ../../../this */
int main(void)
{
	char *path = "./this/and";
	char *full_path = getfull_path(path);
	if (full_path)
	{
		printf("%s\n", full_path);
		free(full_path);
	}
	else
		printf("invalid path\n");
	return (0);
}