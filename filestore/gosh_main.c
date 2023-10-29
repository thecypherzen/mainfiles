#include "gosh.h"
/**
 * main - gosh entry point
 * @argc: number of arguments
 * @argv: vector of arguments
 * @envp: environment pointer
 */
int main(int argc, char **argv, char **envp)
{
	int func_ret = 0, fd, is_atty = isatty(STDIN_FILENO),
	cmd_count = 0;
	ssize_t ret;
	size_t sz = 0, len;
	char *cmd = NULL;
	Info shell;
	
	signal(SIGINT, sig_handler);
	fd = argc > 1 ? open(argv[1], O_RDONLY) : STDIN_FILENO;
	if (fd == -1)
		return (1);
	while (1)
	{
		if (is_atty && argc == 1)
		{
			ret = write(STDOUT_FILENO, "($) ", 4);
			if (ret == -1)
				return (1);
		}
		ret = fd_getline(&cmd, &sz, fd);
		if (ret > 0)
		{
			check_comment(cmd);
			shell = copy_info(argv[0], envp, &func_ret, 
				&cmd_count);
			if ((len = strlen(cmd)))
				func_ret = cmd_prepcheckr(cmd, shell);
		}
		else if (ret == -1)
		{
			if ((ret = write(1, "\n", 1)) != -1)
				break;
			else
				perror("Fatal");
		}
	}
	free(cmd);
	return (func_ret);
}
