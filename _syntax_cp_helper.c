#include "gosh.h"
/**
* _cpyto_cmdstr - a helper to the logical_ops func.
* @token: tokenised commands
* @cmdstr: the arguments passed as commands
* Return: returns 0 for success or 1 if failure
*/
int _syntax_cp_helpr(char *token, char **cmdstr, 
		size_t *cmdsz, Info shell)
{
	int i, k, len, j, match1, match2;
	char c1, c2, s_lops[] = {';', '&', '|', '\0'};

	for (i = 0, k = 0; token[i] && token[i + 1]; i += 2)
	{
		c1 = token[i], c2 = token[i + 1];
		match1 = _slops_cmp(s_lops, c1, c2);
		if (match1 == 1 && c1 != c2)
			return (throw_syntax_err(1, shell, c2));
		match2 = _slops_cmp(s_lops, c2, token[i + 2]);
		if (match1 == 1 && match2 == 1)
			return (throw_syntax_err(1, shell,
				token[i + 2]));
		len = strlen(*cmdstr), j = len ? len : 0;
		if (j >= ((int)*cmdsz - 4))
		{
			*cmdsz += 8;
			*cmdstr = realloc(*cmdstr, *cmdsz);
			if (!(*cmdstr))
				return (NORMAL_FAIL);
		}
		if (j > 0 && !k)
			(*cmdstr)[j] = ' ', j++;
		(*cmdstr)[j] = c1, j++, k++;
		(*cmdstr)[j] = c2, j++;
		if (match1 == 1)
			(*cmdstr)[j] = ' ', j++;
		(*cmdstr)[j] = '\0';
	}
	if (token[i])
	{
		j = strlen(*cmdstr);
		(*cmdstr)[j] = token[i], (*cmdstr)[j + 1] = '\0';
	}
	return (0);
}