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
#define SYNTAX_ERR 		2
#define CMD_EXEC_FAIL	126
#define CMD_NOT_FOUND	127
#define ARG_INVALID	128

/* Custom Types */
typedef struct Alias_t /* Alias info struct */
{
	char *name;
	char *val;
	struct Alias_t *next;
} Alias_t;

typedef struct Env_t /* Env infor struct */
{
	char *name;
	char *val;
	struct Env_t *next;
} Env_t;

typedef struct	/* shell info type struct */
{
	char *name;
	char *file;
	char **envp;
	int *f_ret;
	int *count;
	int isatty;
	Alias_t **alias_h;
	Env_t **env_h;

} Info;

typedef struct	/* shell functions struct */
{
	const char* const cmd;
	int (*func)(char **, Info);
} Toolbox;

/* function selector*/
typedef int (*ftype)(char **, Info);

/* Utility Functions */
void throw_sh_err(char *, Info);
int throw_syntax_err(int, Info, ...);
char **make_vectr(char *, char *);
void free_charptr(char **ptr);
void free_vectr(char **);
void free_structs(Alias_t *, Env_t *);
char *getfull_path(char *path);
	char *_getparent_path(char *cwd);
	char *_getdir_name(char *cwd);
	int _getfpath_copier(char **full_path, char *name, int strt);
	int _getfpath_helpr(char **full_path, char **pwd, char *vecti);
	int _fpath_maker(char **full_path, char **vect, int i);
	char  *str_rev(char *str);

/* Shell functions */
void sig_handler(int sig);
Info copy_info(char *, char *, char **, int *, int *, int,
					Alias_t **, Env_t **);
int shell_mgr(Info);
ssize_t get_line(char **, size_t *, FILE *);
	ssize_t fd_getline(char **, size_t *, int);
	ssize_t _fd_getline_helper(char **, char **, size_t *);
void check_comment(char *);
int cmd_prepcheckr(char *, Info);
int syntax_checkr(char **, char *, Info);
	int _callout_syntax_err(char *, Info);
	int _syntax_token_cmp(char **, char *);
	int _syntax_cp_helpr(char *, char **, size_t *, Info);
	int _slops_cmp(char *, char, char);
int islogical_checkr(char **);
int cmdexec_mgr(char **, char *, Info);
int logicops_exec(char *, Info);
ftype func_selectr(char *, Info);

/* Command Handling Functions */
int alias_exec(char **, Info);
int cat_exec(char **, Info);
int cd_exec(char **, Info);
int echo_exec(char **, Info);
int exit_exec(char **, Info);
int ftype_checkr(char **, Info);
int fork_exec(char **, Info);
int setenv_exec(char **, Info);
int unsetenv_exec(char **, Info);

/* Command Handling Helper functions */
void _printall_aliases(Alias_t *);
void _printan_alias(Alias_t *, char *);
char *_str_dequote(char *, Info);
int _force_terminate(char **, size_t, Info);
char *_strquote_remove(char *);
int _set_alias(Alias_t **, char *, char *);

