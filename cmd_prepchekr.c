#include "gosh.h"

int cmd_prepcheckr(char *cmd, Info shell)
{
	int ret;
	char *cmdstr = NULL, **cmdv = NULL;

	*(shell.count) += 1;
	ret = syntax_checkr(&cmdstr, cmd, shell);
	if (ret)
	{
		if (ret == NORMAL_FAIL)
			throw_sh_err(NULL, shell);
		free(cmdstr);
		return (ret);
	}
	ret = islogical_checkr(&cmdstr);
	if (ret < 0)
	{
		throw_sh_err(NULL, shell);
		return (NORMAL_FAIL);
	}
	if (ret == 1)
	{
		cmdv = make_vectr(cmdstr, ";");
		if (!cmdv)
		{
			free(cmdstr);
			return (NORMAL_FAIL);
		}
		ret = cmdexec_mgr(cmdv, NULL, shell);
		free_vectr(cmdv);
	}
	else
		ret = cmdexec_mgr(NULL, cmdstr, shell);
	free(cmdstr);
	return (ret);
}
