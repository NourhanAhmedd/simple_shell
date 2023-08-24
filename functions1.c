#include "s_shell.h"

/* _inac: */

/**
 * _inac - Write a function that returns true or false.
 *
 * @in: The struct.
 *
 * Return: It will return (isatty(STDIN_FILENO) && in->read_line_input <= 2).
*/
int _inac(p_t *in)
{
	return (isatty(STDIN_FILENO) && in->read_line_input <= 2);
}

/* i_d: */

/**
 * i_d - Write a function that returna if it is a delimeter or not.
 *
 * @s: The character.
 * @di: the delimeter string
 *
 * Return: It will return 1 or 0.
*/

int i_d(char s, char *di)
{
	/* While loop: */
	while (*di)
	{
		/* If condition: */
		if (*di++ == s)
		{
			return (1);
		}
	}
	return (0);
}

/* i_alpha: */

/**
 *i_alpha - Write a function that returns for alpha chars.
 *
 *@ch: The character.
 *
 *Return: It will return 1 or 0.
*/

int i_alpha(int ch)
{
	/* If condition: */
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* atoi_f: */

/**
 *atoi_f - Write a function that converts str to int.
 *
 *@p: The string.
 *
 *Return: 0 if no numbers in string, converted number otherwise
*/

int atoi_f(char *p)
{
	unsigned int t;
	int res, index, si = 1, fg = 0;

	t = 0;
	for (index = 0;  p[index] != '\0' && fg != 2; index++)
	{
		if (p[index] == '-')
		{
			si *= -1;
		}
		if (p[index] >= '0' && p[index] <= '9')
		{
			fg = 1;
			t *= 10;
			t += (p[index] - '0');
		}
		else if (fg == 1)
		{
			fg = 2;
		}
	}
	if (si == -1)
	{
		res = -t;
	}
	else
	{
		res = t;
	}
	return (res);
}
