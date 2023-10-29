#include "gosh.h"

ssize_t fd_getline(char **line, size_t *sz, int fd)
{
	char *buff;
	size_t buffsz = 128, i;
	ssize_t res, n = 0;
	
	buff = malloc(buffsz);
	if (!buff)
		return (-1);
	if (!(*line) || !(*sz))
		*sz = 120, *line = malloc(*sz);
	if (!(*line))
		return (-1);
	i = 0, fflush(stdout);
	while ((res = read(fd, buff + i, 1)) > 0)
	{
		n++, i++;
		if (i == buffsz)
		{
			buffsz += 128, buff = realloc(buff, buffsz);
			if (!buff)
				return (n ? n : -1);
		}
		if (buff[i - 1] == '\n')
		{
			buff[i] = '\0';
			break;
		}
	}
	if (res == 0)
		buff[i] = '\0';
	res = _fd_getline_helper(&buff, line, sz);
	free(buff), buff = NULL;
	if (res < 0)
		return (res);
	return (n ? n : -1);
}