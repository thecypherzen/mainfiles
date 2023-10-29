#include "gosh.h"

ssize_t get_line(char **line, size_t *sz, FILE *stream)
{
	int fd = stream->_fileno;
	
	ssize_t res = fd_getline(line, sz, fd);
	return (res);
}