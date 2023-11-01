#include "gosh.h"
int alias_exec(char **ex_cmdv, Info shell, ...)
{
/*
usage:
alias: Prints a list of all aliases, name='value' per line
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
	 alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
	*/
	printf("alias_exec called\n");
	(void)ex_cmdv, (void)shell;
	return (0);
}