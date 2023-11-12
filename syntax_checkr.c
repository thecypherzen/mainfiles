#include "gosh.h"
/**
 * syntax_checkr - checks for 2 edge cases.
 * 1. Empty commands/syntax errors (multiple operators and separators)
 * 2. Trailing white spaces
 * @cmdstr: ptr to adjusted command string stripped of excess white
 * spaces and of correct syntax.
 * @cmd: the argument passed by user
 * @shell: struct of all shell information
 * Return: should be added to other functions.
 */
int syntax_checkr(char **cmdstr, char *cmd, Info shell)
{
	int matched, ret;
	char *cmdln = strdup(cmd), *token,
	*lops[] = {";", "&&", "||", NULL};
	size_t cmdsz = strlen(cmdln), k = 0;

	*cmdstr = malloc(cmdsz + 1);
	if (!(*cmdstr))
		return (NORMAL_FAIL);
	(*cmdstr)[0] = '\0';
	if (*cmdln == ';' || *cmdln == '&' || *cmdln == '|')
	{
		free(cmdln);
		return (ret = _callout_syntax_err(cmd, shell));
	}
	token = strtok(cmdln, " ");
	while (token)
	{
		matched = _syntax_token_cmp(lops, token);
		if (matched || strlen(token) == 1)
		{
			if (k)
				strcat((*cmdstr), " ");
			strcat((*cmdstr), token);
		}
		else
		{
			ret = _syntax_cp_helpr(token, cmdstr,
				&cmdsz, shell);
			if (ret != 0)
			{
				free(cmdln);
				return (ret);
			}
		}
		token = strtok(NULL, " "), k++;
	}
	free(cmdln);
	return (0);
}
