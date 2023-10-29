#include "gosh.h"
int exit_exec(char **ex_cmdv, Info shell, ...)
{
	printf("exit_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}