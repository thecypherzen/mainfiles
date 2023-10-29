#include "gosh.h"
int cat_exec(char **ex_cmdv, Info shell, ...)
{
	printf("cat_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}