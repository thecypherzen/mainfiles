#include "gosh.h"

/**
 * islogical_checkr - checks if a command line has logical
 * operators
 * @cmdline: the command line
 * Return: 1 if there is at least one logical operator in command
 *	   0 if none, -1 if err.
 */
int islogical_checkr(char **cmdstr)
{
	int is_logical = 0, i;

	if (!cmdstr || !(*cmdstr))
		return (-1);

	for (i = 0; (*cmdstr)[i]; i++) 
	{
		if ((*cmdstr)[i] == '|' || 
			(*cmdstr)[i] == '&' || 
			(*cmdstr)[i] == ';')
		{
			is_logical = 1;
			break;
		}
	}
	return (is_logical);
}
