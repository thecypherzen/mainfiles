#include "gosh.h"
int fork_exec(char **ex_cmdv, Info shell)
{
	size_t i;

	printf("fork_exec called\n");
	for (i = 0; ex_cmdv[i]; i++)
	{
		printf("%s%c", ex_cmdv[i], ex_cmdv[i + 1] ? 32 : 10);
	}
	(void)shell;
	return (0);
}