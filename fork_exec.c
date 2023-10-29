#include "gosh.h"
int fork_exec(char **ex_cmdv, Info shell, ...)
{
	printf("fork_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}