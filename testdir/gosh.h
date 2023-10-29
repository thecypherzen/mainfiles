/*Libraries */
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>

/* Return values */
#define EXEC_SUCCESS 	0
#define NORMAL_FAIL 	1
#define SYNTAX_ERR 	2
#define CMD_EXEC_FAIL	126
#define CMD_NOT_FOUND	127
#define ARG_INVALID	128

/* shell info struct */
typedef struct
{
	char *name;
	char *file;
	char **envp;
	int *f_ret;
	int *count;
	int isatty;
} Info;
/* shell functions struct */
typedef struct
{
	const char* const cmd;
	int (*func)(char **ex_cmdv, Info shell, ...);
} Toolbox;

/* function selector return alias */
typedef int (*ftype)(char **, Info, ...);

/* Aliases & env struct */
typedef struct Alias_t
{
	char *name;
	char *val;
	struct Alias_t *next;
} Alias_t;

typedef struct Env_t
{
	char *name;
	char *val;
	struct Env_t *next;
} Env_t;

/* Utility Functions */
void throw_sh_err(char *, Info);
int throw_syntax_err(int, Info, ...);
char **make_vectr(char *, char *);
void free_vectr(char **);
void free_structs(Alias_t *, Env_t *);
char *_getparent_path(char *cwd);
char *_getdir_name(char *cwd);
char *getfull_path(char *path);
int _getfpath_copier(char **full_path, char *name, int strt);
int _getfpath_helpr(char **full_path, char **pwd, char *vecti);
char  *str_rev(char *str);

/* Shell functions */
void sig_handler(int sig);
Info copy_info(char *, char *, char **, int *, int *, int);
int shell_mgr(Info, Alias_t *, Env_t *);
ssize_t get_line(char **, size_t *, FILE *);
ssize_t fd_getline(char **, size_t *, int);
ssize_t _fd_getline_helper(char **, char **, size_t *);
void check_comment(char *);
int cmd_prepcheckr(char *, Info, Alias_t *, Env_t *);
int syntax_checkr(char **, char *, Info);
int _syntax_token_cmp(char **, char *);
int _syntax_cp_helpr(char *, char **, size_t *, Info);
int _slops_cmp(char *, char, char);
int islogical_checkr(char **);
int cmdexec_mgr(char **, char *, Info, Alias_t *, Env_t *);
int logicops_exec(char *, Info);
ftype func_selectr(char *, Info);

/* Command Handling Functions */
int alias_exec(char **, Info, ...);
int cat_exec(char **, Info, ...);
int cd_exec(char **, Info, ...);
int echo_exec(char **, Info, ...);
int exit_exec(char **, Info, ...);
int ftype_checkr(char **, Info, ...);
int fork_exec(char **, Info, ...);
int setenv_exec(char **, Info, ...);
int unsetenv_exec(char **, Info, ...);




