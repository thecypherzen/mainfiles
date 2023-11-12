#include "gosh.h"
int unsetenv_exec(char **ex_cmdv, Info shell)
{
	printf("unsetenv_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}