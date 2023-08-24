#include "s_shell.h"

/* the_exit: */

/**
 * the_exit - Write a function that exits the file.
 *
 * @in: The para struct.
 * Return: It will return (-2).
*/

int the_exit(p_t *in)
{
	int e_chck;

	if (in->arguement_value[1])
	{
		e_chck = error_at(in->arguement_value[1]);
		if (e_chck == -1)
		{
			in->st = 2;
			p_e(in, "Illegal number: ");
			e_p(in->arguement_value[1]);
			e_p_char('\n');
			return (1);
		}
		in->error_n = error_at(in->arguement_value[1]);
		return (-2);
	}
	in->error_n = -1;
	return (-2);
}

/* the_cd: */

/**
 * the_cd - Write a function that changes the current dir.
 *
 * @in: The para struct.
 *
 * Return: It will return (0).
*/

int the_cd(p_t *in)
{
	int d_r;
	char *d, bu[1024], *p;

	p = getcwd(bu, 1024);
	if (!p)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!in->arguement_value[1])
	{
		d = g_e(in, "HOME=");
		if (!d)
			d_r =
				chdir((d = g_e(in, "PWD=")) ? d : "/");
		else
			d_r = chdir(d);
	}
	else if (s_cmp(in->arguement_value[1], "-") == 0)
	{
		if (!g_e(in, "OLDPWD="))
		{
			_puts(p);
			_putchar('\n');
			return (1);
		}
		_puts(g_e(in, "OLDPWD=")), _putchar('\n');
		d_r =
			chdir((d = g_e(in, "OLDPWD=")) ? d : "/");
	}
	else
		d_r = chdir(in->arguement_value[1]);
	if (d_r == -1)
	{
		p_e(in, "can't cd to ");
		e_p(in->arguement_value[1]), e_p_char('\n');
	}
	else
	{
		se(in, "OLDPWD", g_e(in, "PWD="));
		se(in, "PWD", getcwd(bu, 1024));
	}
	return (0);
}

/* the_help: */

/**
 * the_help - Write a function that changes the current dir.
 *
 * @in: The para struct.
 *
 * Return: It will return (0).
*/

int the_help(p_t *in)
{
	char **ar_arr;

	ar_arr = in->arguement_value;
	_puts("help call works. Function not yet implemented \n");
	/* If condition: */
	if (0)
	{
		_puts(*ar_arr);
	}
	return (0);
}
