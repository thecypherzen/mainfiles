#include "gosh.h"
/**
 * cmdexec_mgr - manages shell command executions
 * @cmdv: vector of logical commands - for logical ops handling
 * @cmdstr: command string - as entered by user - after syntax check
 * @shell: struct of shell information
 * @alias_h: alias list head pointer
 * @env_h: environment variables list head pointer
 * Return: 0 on success, appropriate error macro def on error.
 */
int cmdexec_mgr(char **cmdv, char *cmdstr, Info shell)
{
	int ret = 0, i;
	char **ex_cmdv = NULL, *curr_cmd;
	ftype ifunc;

	if (!cmdstr)
	{
		for (i = 0; cmdv[i]; i++)
			ret = logicops_exec(cmdv[i], shell);
		*(shell.f_ret) = ret;
	}
	else
	{
		curr_cmd = strdup(cmdstr);
		ex_cmdv = make_vectr(curr_cmd, " ");
		if (!ex_cmdv)
		{
			free(curr_cmd);
			throw_sh_err(NULL, shell);
			return (NORMAL_FAIL);
		}
		ifunc = func_selectr(ex_cmdv[0], shell);
		ret = ifunc(ex_cmdv, shell);
		if (ret == NORMAL_FAIL)
			throw_sh_err(NULL, shell);
		else if (ret == CMD_NOT_FOUND)
			throw_sh_err(ex_cmdv[0], shell);
		free_vectr(ex_cmdv), free(curr_cmd);
	}
	return (ret);
}