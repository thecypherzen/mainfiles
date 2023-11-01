#include "gosh.h"

char  *str_rev(char *str)
{
	int len = (int)strlen(str) - 1,
	end = len  / 2,
	i;
	char tmp;

	for (i = 0; i <= end; i++)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
	}
	return (str);
}