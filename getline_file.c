#include "s_shell.h"

/* in_bu: */

/**
 * in_bu - Write a function that returns the buffer.
 *
 * @in: parameter struct
 * @b: The address.
 * @l: The length.
 *
 * Return: It will return (t).
*/

ssize_t in_bu(p_t *in, char **b, size_t *l)
{
	ssize_t t;
	size_t length;

	length = 0;
	t = 0;
	if (!*l)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, s_hand);
#if GETLINE
		t = getline(b, &length, stdin);
#else
		t = the_l(in, b, &length);
#endif
		/* If condition */
		if (t > 0)
		{
			if ((*b)[t - 1] == '\n')
			{
				(*b)[t - 1] = '\0';
				t--;
			}
			in->lcount_f = 1;
			delete_comm(*b);
			bu_hist(in, *b, in->hist_line++);
			{
				*l = t;
				in->cmd_b = b;
			}
		}
	}
	return (t);
}

/* the_i: */

/**
 * the_i - gets a line minus the newline
 *
 * @in: The param struct.
 *
 * Return: It will return (t).
*/

ssize_t the_i(p_t *in)
{
	static size_t index1, index2;
	static size_t length;
	static char *bu;
	ssize_t t = 0;
	char *s;
	char **b_p = &(in->arguement);

	_putchar(BUFFER_F);
	t = in_bu(in, &bu, &length);
	/* If condition: */
	if (t == -1)
	{
		return (-1);
	}
	/* If condition: */
	if (length)
	{
		index2 = index1;
		s = bu + index1;
		chck_ch(in, bu, &index2, index1, length);
		/* while loop: */
		while (index2 < length)
		{
			if (the_chain(in, bu, &index2))
			{
				break;
			}
			index2++;
		}
		index1 = index2 + 1;
		if (index1 >= length)
		{
			index1 = length = 0;
			in->cmd_b_t = C_NORM;
		}
		*b_p = s;
		return (s_len(s));
	}
	*b_p = bu;
	return (t);
}

/* re_bu: */

/**
 * re_bu - Write a function that reads the buf.
 *
 * @in: The para struct.
 * @b: The buffer.
 * @si: The buffer size.
 *
 * Return: It will return (t).
*/

ssize_t re_bu(p_t *in, char *b, size_t *si)
{
	ssize_t t;

	t = 0;
	if (*si)
	{
		return (0);
	}
	t = read(in->read_line_input, b, R_BUFFER_S);
	if (t >= 0)
	{
		*si = t;
	}
	return (t);
}

/* the_l: */

/**
 * the_l - Write a function that returns the next line.
 *
 * @in: The para struct.
 * @s: The address.
 * @l: The size.
 *
 * Return: It will return (ps).
*/

int the_l(p_t *in, char **s, size_t *l)
{
	static char bu[R_BUFFER_S];
	ssize_t ps = 0, t = 0;
	char *n_d = NULL, *a, *d = NULL;
	static size_t index1, length;
	size_t index2;

	d = *s;
	/* If condition: */
	if (d && l)
		ps = *l;
	if (index1 == length)
		index1 = length = 0;
	t = re_bu(in, bu, &length);
	if (t == -1 || (t == 0 && length == 0))
	{
		return (-1);
	}
	a = s_ch(bu + index1, '\n');
	index2 = a ? 1 + (unsigned int)(a - bu) : length;
	n_d = re_all(d, ps, ps ? ps + index2 : index2 + 1);
	if (!n_d)
		return (d ? free(d), -1 : -1);
	if (ps)
		sn_cat(n_d, bu + index1, index2 - index1);
	else
		sn_copy(n_d, bu + index1, index2 - index1 + 1);
	ps = ps + index2 - index1;
	index1 = index2;
	d = n_d;
	if (l)
	{
		*l = ps;
	}
	*s = d;
	return (ps);
}

/* s_hand: */

/**
 * s_hand - Write a function that blocks the (ctrl-c).
 *
 * @s_number: The S numbers.
*/

void s_hand(__attribute__((unused))int s_number)
{
	/* puts function: */
	_puts("\n");
	_puts("$ ");
	/* putchar function: */
	_putchar(BUFFER_F);
}
