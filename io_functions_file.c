#include "s_shell.h"

/* g_hist_f: */

/**
 * g_hist_f - Write a function that returns the hist file.
 *
 * @in: The para struct.
 *
 * Return: It will return (bu).
*/

char *g_hist_f(p_t *in)
{
	char *d;
	char *bu;

	d = g_e(in, "HOME=");
	/* If condition: */
	if (!d)
	{
		return (NULL);
	}
	bu = malloc(sizeof(char) * (s_len(d) + s_len(HISTORY_F) + 2));
	/* If condition: */
	if (!bu)
	{
		return (NULL);
	}
	bu[0] = 0;
	s_copy(bu, d);
	s_cat(bu, "/");
	s_cat(bu, HISTORY_F);
	return (bu);
}

/* w_hist: */

/**
 * w_hist - Write a function that creates a file.
 *
 * @in: The para struct.
 *
 * Return: It will return 1 or 0.
*/

int w_hist(p_t *in)
{
	list_t *n = NULL;
	ssize_t f;
	char *f_n = g_hist_f(in);

	if (!f_n)
	{
		return (-1);
	}

	f = open(f_n, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_n);
	if (f == -1)
	{
		return (-1);
	}
	for (n = in->hist_n; n; n = n->next)
	{
		puts_f(n->str, f);
		put_f('\n', f);
	}
	put_f(BUFFER_F, f);
	close(f);
	return (1);
}

/* r_hist: */

/**
 * r_hist - Write a function that reads from file.
 *
 * @in: The para struct.
 *
 * Return: It will return (in->hist_line).
*/

int r_hist(p_t *in)
{
	ssize_t f, f_s = 0, r_l;
	int lt = 0, l_c = 0, index1;
	char *f_n = g_hist_f(in), *bu = NULL;
	struct stat st;

	if (!f_n)
		return (0);
	f = open(f_n, O_RDONLY);
	free(f_n);
	if (f == -1)
		return (0);
	if (!fstat(f, &st))
		f_s = st.st_size;
	if (f_s < 2)
		return (0);
	bu = malloc(sizeof(char) * (f_s + 1));
	if (!bu)
		return (0);
	r_l = read(f, bu, f_s);
	bu[f_s] = 0;
	if (r_l <= 0)
		return (free(bu), 0);
	close(f);
	for (index1 = 0; index1 < f_s; index1++)
		if (bu[index1] == '\n')
		{
			bu[index1] = 0;
			bu_hist(in, bu + lt, l_c++);
			lt = index1 + 1;
		}
	if (lt != index1)
		bu_hist(in, bu + lt, l_c++);
	free(bu);
	in->hist_line = l_c;
	while (in->hist_line-- >= HISTORY_M)
		remove_node_indx(&(in->hist_n), 0);
	ren_hist(in);
	return (in->hist_line);
}

/* bu_hist: */

/**
 * bu_hist - Write a function that adds entry.
 *
 * @in: The para struct.
 * @b: The buffer.
 * @l_ct: The count.
 *
 * Return: It will return (0).
*/

int bu_hist(p_t *in, char *b, int l_ct)
{
	list_t *n = NULL;

	/* If condition: */
	if (in->hist_n)
	{
		n = in->hist_n;
	}
	add_node_end(&n, b, l_ct);
	/* If condition: */
	if (!in->hist_n)
	{
		in->hist_n = n;
	}
	return (0);
}

/* ren_hist: */

/**
 * ren_hist - Write a function that renumbers the hist.
 *
 * @in: The para struct.
 *
 * Return: It will return (in->hist_line = index).
*/

int ren_hist(p_t *in)
{
	int index;
	list_t *n = in->hist_n;

	index = 0;
	/* While loop: */
	while (n)
	{
		n->num = index++;
		n = n->next;
	}
	return (in->hist_line = index);
}
