#include "gosh.h"
/**
 * main - gosh entry point
 * @argc: number of arguments
 * @argv: vector of arguments
 * @envp: environment pointer
 */
int main(int argc, char **argv, char **envp)
{
	int func_ret = 0, cmd_count = 0, ret,
	is_atty = isatty(STDIN_FILENO);
	Info shell;
	Alias_t *alias_h = NULL;
	Env_t *env_h = NULL;
	char *file = argc > 1 ? argv[1] : NULL;
	
	signal(SIGINT, sig_handler);
	shell = copy_info(argv[0], file, envp, &func_ret, 
			&cmd_count, is_atty);
	ret = shell_mgr(shell, alias_h, env_h);
	if (ret == -1)
	{
		free_structs(alias_h, env_h);
		return (EXIT_SUCCESS);
	}
	return (func_ret = ret);
}
