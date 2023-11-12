#include "gosh.h"

int _callout_syntax_err(char *cmdln, Info shell)
{
	int ret;

	if (cmdln[1] == ';' || cmdln[1] == '&' || cmdln[1] == '|')
			ret = throw_syntax_err(2, shell, cmdln[0],
				cmdln[1]);
		else
			ret = throw_syntax_err(1, shell, cmdln[0]);
	return (ret);
}
