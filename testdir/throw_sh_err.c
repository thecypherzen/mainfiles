#include "gosh.h"

void throw_sh_err(char *cmd, Info shell)
{

	if (!cmd)
	{
		fprintf(stderr, "%s: %d: ", shell.name, 
			*(shell.count));
		perror("Fatal");
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: %s\n", shell.name,
			*(shell.count), cmd, "not found");
	}
}