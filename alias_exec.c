#include "gosh.h"
int alias_exec(char **ex_cmdv, Info shell, ...)
{
	printf("alias_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}