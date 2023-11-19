#include "gosh.h"

int shell_mgr(Info shell)
{
	int ret = 0, fd;
	char *cmd = NULL;
	size_t sz = 0, len;

	fd = shell.isatty && shell.file ?
		open(shell.file, O_RDONLY) : STDIN_FILENO;
	if (fd == -1)
		return (ret = 1);
	while (1)
	{
		if (shell.isatty && !(shell.file))
		{
			ret = write(STDOUT_FILENO, "($) ", 4);
			if (ret == -1)
				return (ret = 1);
		}
		ret = fd_getline(&cmd, &sz, fd);
		if (ret > 0)
		{
			cmd[ret - 1] = '\0', check_comment(cmd), len = strlen(cmd);
			if (len)
			{
				ret = cmd_prepcheckr(cmd, shell);
				*(shell.f_ret) = ret;
			}
		}
		if (ret == -1)
		{
			if (fd != STDIN_FILENO)
				close(fd);
			if ((fd = write(1, "\n", 1)) != -1)
				break;
		}
	}
	free(cmd);
	return (ret);
}