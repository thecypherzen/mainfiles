#include "gosh.h"

int exec_mgr(int fd, int *func_ret, char *currcmd)
{
	char *gcmd = NULL, *err_token;
	size_t sz = 0;
	ssize_t res;

	if ((res = fd_getline(fd, &gcmd, &sz)) > 0)
	{
		res = syntax_checker(gcmd);
		if (res == 1)
			return (2);
		/* check for syntax errors */
		/* if any, throw syntax error & return -1 */
		/* if no syntax err, checks if cmd is logical */
		/* if logical, pass to logical exec func */
		/* else, pass to gcmd exec func */
	}
	else if (res == -1)
		return (-2);
}

/* 
if ((fd = open(argv[1], O_RDONLY)) == -1)
	return (1);
else
	func_ret = exec_mgr(fd, &func_ret, currcmd);


 while (1)
 {
	 if ((res = write(STDOUT_FILENO, "($) ", 4)) 
		 != -1)			
		 func_ret = exec_mgr(STDIN_FILENO, 
			 &func_ret, currcmd);
		 if (func_ret)
	 else
		 break;
 }
*/