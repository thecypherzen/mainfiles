#include "gosh.h"

/**
 * _str_dequoter - removes enclosing quotation marks(' or ") from
 * a string
 * @str: the string
 * @shell: shell information structure
 * Return: NULL on error, ptr to unquoted string on success
 */

char *_str_dequote(char *str, Info shell)
{
	char *lstr, *ad_str = NULL;
	size_t len;
	int ret;

	if (!str)
	{
		errno = SIGSEGV, throw_sh_err(NULL, shell);
		return (NULL);
	}
	len = strlen(str), lstr = malloc(len + 1);
	if (!lstr)
	{
		throw_sh_err(NULL, shell);
		return (NULL);
	}
	lstr[0] = '\0', strcat(lstr, str);

	/* force quote termination and proceed to unquote */
	ret = _force_terminate(&lstr, len, shell);
	if (ret == NORMAL_FAIL)
	{
		free(lstr);
		return (NULL);
	}
	ad_str = _strquote_remove(lstr);
	if (!ad_str)
	{
		free (lstr);
		throw_sh_err(NULL, shell);
		return (NULL);
	}
	free(lstr);
	return (ad_str);
}

/**
 * _force_terminate - ensures a string beginning with a quotation
 * mark (' or ") is closed by same value.
 * @lstr: ptr to local string (in parent func)
 * @len: len of lstr
 * Return: NORMAL_FAIL if malloc fails, 0 otherwise
 */
int _force_terminate(char **lstr, size_t len, Info shell)
{
	char *tmp = NULL;
	size_t sz = 0;
	ssize_t ret;

	if ((**lstr == '"' && (*lstr)[len - 1] != '"')
		|| (**lstr == '\'' && (*lstr)[len - 1] != '\''))
	{
		while (1)
		{
			printf("> ");
			ret = get_line(&tmp, &sz, stdin);
			if (ret < 0)
			{
				if (tmp)
					free(tmp), printf("freed tmp\n");
				return (NORMAL_FAIL);
			}
			tmp[ret - 1] = '\0', len += strlen(tmp) + 1;
			*lstr = realloc(*lstr, len);
			if (!(*lstr))
			{
				throw_sh_err(NULL, shell);
				return (NORMAL_FAIL);
			}
			strcat(*lstr, tmp), len = strlen(*lstr);
			if ((*lstr)[len - 1] == (*lstr)[0])
			{
				free(tmp);
				break;
			}
		}
	}
	return (0);
}
/**
 * _strquote_remove - removes quotes from a string if it exists
 * @lstr: the string
 * Return: the de-quoted string
 */
char *_strquote_remove(char *lstr)
{
	size_t len, i, j, quoted = 0, stp;
	char *ad_str;

	if (!lstr)
		return (NULL);
	if (lstr[0] == '\'' || lstr[0] == '"')
		len = strlen(lstr) - 1, quoted = 1;
	else
		len = strlen(lstr) + 1;
	ad_str = malloc(len);
	if (!ad_str)
		return (NULL);

	len = strlen(lstr);
	i = quoted ? 1 : 0;
	stp = quoted ? len - 1 : len;
	for (j = 0; i < stp; i++, j++)
	{
		ad_str[j] = lstr[i];
	}
	ad_str[j] = '\0';
	return (ad_str);
}