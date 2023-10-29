#include "gosh.h"
/**
 * _syntax_checkr - checks for 2 edge cases.
 * 1. Empty commands/syntax errors (multiple operators and separators)
 * Trailing white spaces
 * @cmdstr: the command string
 * @gcmdln: the argument passed by user
 * Return: should be added to other functions.
 */
int syntax_checkr(char **cmdstr, char *cmd, Info shell)
{
	int matched, ret;
	char *cmdln = strdup(cmd), *token, 
	*lops[] = {";", "&&", "||", NULL};
	size_t cmdsz = strlen(cmdln);

	*cmdstr = malloc(cmdsz + 1);
	if (!(*cmdstr))
		return (NORMAL_FAIL);
	(*cmdstr)[0] = '\0';
	if (*cmdln == ';' || *cmdln == '&' || *cmdln == '|')
	{
		if (cmdln[1] == ';' || cmdln[1] == '&' || cmdln[1] == '|')
			ret = throw_syntax_err(2, shell, cmdln[0], 
				cmdln[1]);
		else
			ret = throw_syntax_err(1, shell, cmdln[0]);
		free(cmdln);
		return (ret);
	}
	token = strtok(cmdln, " ");
	while (token)
	{
		matched = _syntax_token_cmp(lops, token);
		if (matched || strlen(token) == 1)
			strcat((*cmdstr), " "), strcat((*cmdstr), token);
		else
		{
			if ((ret = _syntax_cp_helpr(token, cmdstr, 
				&cmdsz, shell)) != 0)
			{
				free(cmdln);
				return (ret);
			}
		}
		token = strtok(NULL, " ");
	}
	free(cmdln);
	return (0);
}
