#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define MAX_PATH_LEN

typedef struct passinfo
{
char *arg;
char **argv;
char *buf;
@@ -20, 5 + 24, 18 @@ int argc;
char **cmd_buf;
int main(int ac, char **av);
int status;
int main(int argc, char **argv);
int builtin_cd(char **args);
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
} info_t;

/* ENVIRON */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite)
int _unsetenv(const char *name);

/* MEMO_C */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void *realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_string(char **ptr);

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/* main.c */
void shell_interactive(void);
void shell_no_interactive(void);

/* shell_interactive.c */
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);

/* execute_args */
int new_process(char **args);

/* shell_no_interactive */
char *read_stream(void);

/*---Builtin func---*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

/*_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/*_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/*_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

#endif
