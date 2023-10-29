#include "gosh.h"
/**
 * s_lops_cmp - compares if two characters equate to a logical op
 * @s_lops: the s logical operator
 * @a: the first char
 * @b: the second char
 * Return: 0 if they don't match, 1 if there is a match.
 */
int _slops_cmp(char *s_lops, char a, char b)
{
	int a_match = 0, b_match = 0, i = 0;

	if (a == b)
	{
		for (i = 0; s_lops[i]; i++)
		{
			if (s_lops[i] == a)
			{
				a_match = 1;
				break;
			}
		}
		return (a_match);
	}
	else
	{
		for (i = 0; s_lops[i]; i++)
		{
			if (s_lops[i] == a)
			{
				a_match = 1;
				break;
			}
		}
		for (i = 0; s_lops[i]; i++)
		{
			if (s_lops[i] == b)
			{
				b_match = 1;
				break;
			}
		}
		if (a_match && b_match)
			return (1);
		return (0);
	}
}
