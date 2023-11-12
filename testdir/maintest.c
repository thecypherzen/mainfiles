#include "gosh.h"

int main(int argc, char **argv)
{
	char str[] = "efghijk'l", *adjusted;
	int cmd_count = 0, func_ret = 0;
	Info shell;

	shell = copy_info(argv[0], argv[0], NULL,
			&func_ret, &cmd_count, 1);
	adjusted = _str_dequote(str, shell);
	printf("[ main ] adjusted string: %s\n", adjusted ? adjusted : "(null)");
	free(adjusted);
	(void)argc;
	return (0);
}