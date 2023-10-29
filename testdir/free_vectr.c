#include "gosh.h"

void free_vectr(char **vectr)
{
	int i;
	if (vectr)
	{
		for (i = 0; vectr[i]; i++)
		{
			free(vectr[i]);
		}
		free(vectr);
		vectr = NULL;
	}
}