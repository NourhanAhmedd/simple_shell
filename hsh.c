#include "s_shell.h"

/* f_hsh: */

/**
 * f_hsh - Write a function that makes the shell loop.
 *
 * @in: Return the struct.
 * @a_v: The argument value.
 *
 * Return: It will return (bu_r).
*/

int f_hsh(p_t *in, char **a_v)
{
	int bu_r;
	ssize_t t;

	bu_r = 0;
	t = 0;
	while (t != -1 && bu_r != -2)
	{
		c_inf(in);
		if (_inac(in))
			_puts("$ ");
		e_p_char(BUFFER_F);
		t = the_i(in);
		if (t != -1)
		{
			s_inf(in, a_v);
			bu_r = f_b(in);
			if (bu_r == -1)
				f_cmd(in);
		}
		else if (_inac(in))
			_putchar('\n');
		f_inf(in, 0);
	}
	w_hist(in);
	f_inf(in, 1);
	if (!_inac(in) && in->st)
		exit(in->st);
	if (bu_r == -2)
	{
		if (in->error_n == -1)
			exit(in->st);
		exit(in->error_n);
	}
	return (bu_r);
}

/* f_b: */

/**
 * f_b - Write a function that finds the b commands.
 *
 * @in: Return the struct.
 *
 * Return: It will return (r).
*/

int f_b(p_t *in)
{
	int r;
	int index;
	b_table bu[] = {
		{"exit", the_exit},
		{"env", the_e},
		{"help", the_help},
		{"history", the_hist},
		{"setenv", the_se},
		{"unsetenv", the_unse},
		{"cd", the_cd},
		{"alias", the_alias},
		{NULL, NULL}
	};

	r = -1;
	for (index = 0; bu[index].type; index++)
		if (s_cmp(in->arguement_value[0], bu[index].type) == 0)
		{
			in->l_count++;
			r = bu[index].func(in);
			break;
		}
	return (r);
}

/* f_cmd: */

/**
 * f_cmd - Write a function that finds a cmd.
 *
 * @in: the parameter & return info struct
*/

void f_cmd(p_t *in)
{
	int index1;
	int index2;
	char *p = NULL;

	in->p = in->arguement_value[0];
	if (in->lcount_f == 1)
	{
		in->l_count++;
		in->lcount_f = 0;
	}
	for (index1 = 0, index2 = 0; in->arguement[index1]; index1++)
		if (!i_d(in->arguement[index1], " \t\n"))
		{
			index2++;
		}
	if (!index2)
	{
		return;
	}
	p = f_path(in, g_e(in, "PATH="), in->arguement_value[0]);
	if (p)
	{
		in->p = p;
		fk_cmd(in);
	}
	else
	{
		if ((_inac(in) || g_e(in, "PATH=")
			|| in->arguement_value[0][0] == '/') && the_cmd(in, in->arguement_value[0]))
			{
			fk_cmd(in);
			}
		else if (*(in->arguement) != '\n')
		{
			in->st = 127;
			p_e(in, "not found\n");
		}
	}
}

/* fk_cmd: */

/**
 * fk_cmd - Write a function that runs the cmd.
 *
 * @in: Return the struct.
*/

void fk_cmd(p_t *in)
{
	pid_t c_p = fork();

	/* If condition: */
	if (c_p == -1)
	{
		perror("Error:");
		return;
	}
	/* If condition: */
	if (c_p == 0)
	{
		if (execve(in->path_pointer, in->arguement_value, g_environ(in)) == -1)
		{
			f_inf(in, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(in->st));
		/* If condition: */
		if (WIFEXITED(in->st))
		{
			in->st = WEXITSTATUS(in->st);
			if (in->st == 126)
				p_e(in, "Permission denied\n");
		}
	}
}
