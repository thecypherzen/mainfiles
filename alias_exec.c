#include "gosh.h"

/**
 * alias_exec - handles execution of alias commands
 * @ex_cmdv: executable commands vector
 * @shell: struct of shell information
 * Return: 0 on success, 1 on malloc fail
 */
int alias_exec(char **ex_cmdv, Info shell)
{

	Alias_t **alias_h = shell.alias_h;
	char *tmp, *name = NULL, *val = NULL;
	int i, ret;

	if (!ex_cmdv[1])
		_printall_aliases(*alias_h);
	else
	{
		for (i = 1; ex_cmdv[i]; i++)
		{
			tmp = strchr(ex_cmdv[i], '=');
			if (tmp)
			{
				name = strtok(ex_cmdv[i], "=");
				if (name)
				{
					tmp = strtok(NULL, "=");
					val = _str_dequote(tmp ? tmp : "", shell);
					if (!val && errno == EOF)
						return (0);
					ret = _set_alias(alias_h, name, val);
					if (ret == EOF)
						throw_sh_err(ex_cmdv[i], shell);
					free(val);
				}
				else
					fprintf(stderr, "alias: %s not found\n", ex_cmdv[i]);
			}
			else
				_printan_alias(*alias_h, ex_cmdv[i]);
		}
	}
	return (0);
}

/**
 * _printall_aliases - prints all shell aliases
 * @alias_h: pointer to start of list
 * Return: void
 */
void _printall_aliases(Alias_t *alias_h)
{
	Alias_t *alias = alias_h;

	if (alias)
	{
		while (alias)
		{
			printf("alias %s='%s'\n", alias->name, alias->val);
			alias = alias->next;
		}
	}
}

/**
 * _printan_alias - prints an alias name and value if found
 * @alias_h: alias list head
 * @name: name of alias to pring
 * Return: void
 */
void _printan_alias(Alias_t *alias_h, char *name)
{
	Alias_t *alias = alias_h;
	int found = 0;

	while (alias)
	{
		if (strcmp(alias->name, name) == 0)
		{
			printf("\t[**] alias %s='%s'\n", alias->name, alias->val);
			found++;
			break;
		}
		alias = alias->next;
	}
	if (!found)
		fprintf(stderr, "alias: %s not found\n", name);
}
/**
 * _set_alias - sets a new alias value
 * @alias_h: alias list head ptr
 * @nme: alias name
 * @val: new alias value
 * Return: 0 on success, EOF on malloc failure
 */
int _set_alias(Alias_t **alias_h, char *nme, char *val)
{
	Alias_t *temp, *new_alias;

	/* If name exists, reset its value */
	temp = *alias_h;
	while (temp)
	{
		if (strcmp(temp->name, nme) == 0)
			break;
		temp = temp->next;
	}
	if (temp)
	{
		free(temp->val);
		temp->val = strdup(val);
		return (EXIT_SUCCESS);
	}

	/* Define new alias */
	new_alias = malloc(sizeof(Alias_t));
	if (!new_alias)
		return (EOF);
	new_alias->name = strdup(nme);
	new_alias->val = strdup(val);
	new_alias->next = NULL;

	/* Insert new alias into list */
	if (!(*alias_h))
		*alias_h = new_alias;
	else
	{
		temp = *alias_h;
		while (temp->next)
			temp = temp->next;
		temp->next = new_alias;
	}
	return (EXIT_SUCCESS);
}
