#include "s_shell.h"

/* the_cmd: */

/**
 * the_cmd - Write a function that returns if it is an executable or not.
 *
 * @in: The struct.
 * @p: The path.
 *
 * Return: It will return 1 or 0.
*/

int the_cmd(p_t *in, char *p)
{
	struct sa sp;

	(void)in;
	/* If condition: */
	if (!p || sa(p, &sp))
	{
		return (0);
	}
	/* If condition: */
	if (sp.st_mode & S_IFREG)
	{
		return (1);
	}

	return (0);
}

/* d_ch: */

/**
 * d_ch - Write a function that duplicates strings.
 *
 * @p_s: The str path.
 * @s: The start.
 * @e: The end.
 *
 * Return: It will return (buffer).
*/

char *d_ch(char *p_s, int s, int e)
{
	int index1;
	int index2;
	static char buffer[1024];

	index1 = 0;
	index2 = 0;
	/* For loop: */
	for (index2 = 0, index1 = s; index1 < e; index1++)
	{
		/* If condition: */
		if (p_s[index1] != ':')
		{
			buffer[index2++] = p_s[index1];
		}
	}
	buffer[index2] = 0;

	return (buffer);
}

/* f_path: */

/**
 * f_path - Write a function that returns the cmd path.
 *
 * @in: The struct.
 * @p_s: The string path.
 * @c: The cmd.
 *
 * Return: It will return the cmd path or NULL
*/

char *f_path(p_t *in, char *p_s, char *c)
{
	char *p;
	int index;
	int c_p;

	index = 0;
	c_p = 0;
	if (!p_s)
		return (NULL);
	if ((s_len(c) > 2) && s_with(c, "./"))
	{
		if (the_cmd(in, c))
			return (c);
	}
	while (1)
	{
		if (!p_s[index] || p_s[index] == ':')
		{
			p = d_ch(p_s, c_p, index);
			if (!*p)
				s_cat(p, c);
			else
			{
				s_cat(p, "/");
				s_cat(p, c);
			}
			if (the_cmd(in, p))
				return (p);
			if (!p_s[index])
				break;
			c_p = index;
		}
		index++;
	}
	return (NULL);
}
