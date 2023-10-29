#include "gosh.h"
/**
 * copy_info - copies shell info into struct
 * @name: shell name
 * @envp: shell env pointer
 * @func_ret: ptr to last function return value
 * @cmd_count: ptr to current count of command
 * Return: a shell info struct.
 */
Info copy_info(char *name, char *file, char **envp, 
			int *func_ret, int *cmd_count, int isatty)
{
	Info shell;
	
	shell.name = name;
	shell.file = file;
	shell.envp = envp;
	shell.f_ret = func_ret;
	shell.count = cmd_count;
	shell.isatty = isatty;
	return (shell);
}