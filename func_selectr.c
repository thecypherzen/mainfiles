#include "gosh.h"

/**
 * func_selectr - selects a command executing function.
 * @cmd: the command
 * Return: ptr to built_in function if found. Otherewise,
 * returns ptr to fork_exec function that uses the path.
 */
ftype func_selectr(char *cmd, Info shell)
{
	Toolbox builtins[] = 
	{
		{"alias", alias_exec}, {"cat", cat_exec},
		{"cd", cd_exec}, {"echo", echo_exec},
		{"exit", exit_exec}, {"setenv", setenv_exec},
		{"unsetenv", unsetenv_exec},
		{"type", ftype_checkr}, {NULL, NULL}
	};
	int i, match = 0;
	
	if (!cmd)
	{
		errno = SIGSEGV;
		throw_sh_err(NULL, shell);
		return (NULL);
	}
	for (i = 0; builtins[i].cmd; i++)
	{
		if (strcmp(builtins[i].cmd, cmd) == 0)
		{
			match = 1;
			break;
		}
	}
	if (match)
		return (builtins[i].func);
	return (fork_exec);
}