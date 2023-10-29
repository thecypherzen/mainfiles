#include "gosh.h"
int echo_exec(char **ex_cmdv, Info shell, ...)
{
	printf("echo_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}