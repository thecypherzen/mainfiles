#include "gosh.h"

int shell_mgr(Info shell, Alias_t *alias_h, Env_t *env_h)
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
			check_comment(cmd);
			if ((len = strlen(cmd)))
				ret = cmd_prepcheckr(cmd, shell,
					alias_h, env_h);
			*(shell.f_ret) = ret;
		}
		if (ret == -1)
		{
			if (fd != STDIN_FILENO)
				close(fd);
			if ((ret = write(1, "\n", 1)) != -1)
				break;
			perror("Fatal");
		}
	}
	free(cmd);
	return (ret);
}