#include "gosh.h"
int setenv_exec(char **ex_cmdv, Info shell, ...)
{
	printf("setenv_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}