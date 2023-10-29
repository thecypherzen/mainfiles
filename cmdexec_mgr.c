#include "gosh.h"

int cmdexec_mgr(char **cmdv, char *cmdstr, Info shell,
			Alias_t *alias_h, Env_t *env_h)
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
		ret = ifunc(ex_cmdv, shell, alias_h, env_h);
		if (ret == NORMAL_FAIL)
			throw_sh_err(NULL, shell);
		else if (ret == CMD_NOT_FOUND)
			throw_sh_err(ex_cmdv[0], shell);
		free_vectr(ex_cmdv), free(curr_cmd);
	}
	return (ret);
}