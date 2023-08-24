#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* The libraries: */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

/* Define: */

#define BUFFER_F -1
#define R_BUFFER_S 1024
#define W_BUFFER_S 1024

#define C_OR 1
#define C_AND 2
#define C_NORM 0
#define C_CHAIN	3
#define CONV_LCASE 1
#define CONV_UNSIGNED_NUMBERS 2

#define HISTORY_F ".simple_shell_history"
#define HISTORY_M 4096
#define GETLINE 0
#define STRTOK 0

extern char **environ_copy;

/* Struct (1): */

/**
 * struct list_string - The linked list.
 * @num: The number.
 * @str: The string.
 * @next: The pointer.
*/
typedef struct list_string
{
	int num;
	char *str;
	struct list_string *next;
} l_t;


/* Struct (2): */

/**
 *struct pass_into_function - The pseudo args to pass into the function.
 *@arguement: The arguements.
 *@arguement_value: The arguement value.
 *@path_pointer: The path.
 *@arguement_c: This is the argument count.
 *@l_count: The line count.
 *@error_n: The error name.
 *@lcount_f: The line of input.
 *@file_name: The filename.
 *@environ_linked_list: The linked list of environ.
 *@hist_n: This is the hist node.
 *@al_n: This is the alias.
 *@environ_copy: The copy of environ.
 *@environ_c: The changes of the environ.
 *@st: The status.
 *@cmd_b: The addr of pointer.
 *@cmd_b_t: The cmd type.
 *@read_line_input: Read the line input.
 *@hist_line: This is the hist line number.
*/
typedef struct pass_into_function
{
	char *arguement;
	char **arguement_value;
	char *path_pointer;
	int arguement_c;
	unsigned int l_count;
	int error_n;
	int lcount_f;
	char *file_name;
	l_t *environ_linked_list;
	l_t *hist_n;
	l_t *al_n;
	char **environ_copy;
	int environ_c;
	int st;
	char **cmd_b;
	int cmd_b_t;
	int read_line_input;
	int hist_line;
} p_t;

#define INFO_NUMBERS \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/* Struct (3): */

/**
 *struct b_s - The builtin string.
 *@type: The builtin type.
 *@func: The builtin function.
*/
typedef struct b_s
{
	char *type;
	int (*func)(p_t *);
} b_table;


/* The functions: */

int the_cmd(p_t *, char *);
char *f_path(p_t *, char *, char *);
char *d_ch(char *, int, int);

void fk_cmd(p_t *);
int f_hsh(p_t *, char **);
void f_cmd(p_t *);
int f_b(p_t *);

int l_hsh(char **);

int put_f(char ch, int f);
int puts_f(char *s, int f);
void e_p(char *);
int e_p_char(char);

int s_len(char *);
char *s_cat(char *, char *);
int s_cmp(char *, char *);
char *s_with(const char *, const char *);

char **st1(char *, char *);
char **st2(char *, char);

void _puts(char *);
int _putchar(char);

char *s_copy(char *, char *);
char *s_dup(const char *);

char *s_ch(char *, char);
char *sn_copy(char *, char *, int);
char *sn_cat(char *, char *, int);

int free_b(void **);

int i_d(char, char *);
int i_alpha(int);
int _inac(p_t *);
int atoi_f(char *);

void file_free(char **);
char *m_set(char *, char, unsigned int);
void *re_all(void *, unsigned int, unsigned int);

int p_d(int, int);
char *conv_num(long int, int, int);
int error_at(char *);
void p_e(p_t *, char *);
void delete_comm(char *);

int the_hist(p_t *);
int the_alias(p_t *);

void c_inf(p_t *);
void s_inf(p_t *, char **);
void f_inf(p_t *, int);

int the_exit(p_t *);
int the_help(p_t *);
int the_cd(p_t *);

ssize_t the_i(p_t *);
void s_hand(int);
int the_l(p_t *, char **, size_t *);

int the_unse(p_t *);
char *g_e(p_t *, const char *);
int the_e(p_t *);
int the_se(p_t *);
int p_elist(p_t *);

int unse(p_t *, char *);
char **g_environ(p_t *);
int se(p_t *, char *, char *);

char *g_hist_f(p_t *in);
int w_hist(p_t *in);
int bu_hist(p_t *in, char *b, int l_ct);
int ren_hist(p_t *in);
int r_hist(p_t *in);

size_t p_l_s(const l_t *);
int remove_node_indx(l_t **, unsigned int);
void li_free(l_t **);
l_t *new_node(l_t **, const char *, int);
l_t *new_node_e(l_t **, const char *, int);

size_t length_li(const l_t *);
l_t *node_st(l_t *, char *, char);
ssize_t node_indx(l_t *, l_t *);
char **list_str(l_t *);
size_t p_li(const l_t *);

int the_chain(l_t *, char *, size_t *);
int rep_v(l_t *);
int rep_str(char **, char *);
void chck_ch(l_t *, char *, size_t *, size_t, size_t);
int rep_ali(l_t *);

#endif /* SIMPLE_SHELL_H */
