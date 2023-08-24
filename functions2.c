#include "s_shell.h"

/* error_at: */

/**
 * error_at - Write a function that converts the string.
 *
 * @p: The string.
 *
 * Return: It will return (t).
*/

int error_at(char *p)
{
	unsigned long int t;
	int index;

	index = 0;
	t = 0;
	/* If condition: */
	if (*p == '+')
	{
		p++;
	}
	/* For loop: */
	for (index = 0;  p[index] != '\0'; index++)
	{
		/* If condition: */
		if (p[index] >= '0' && p[index] <= '9')
		{
			t = t * 10;
			t = t + (p[index] - '0');
			/* If condition: */
			if (t > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
	return (t);
}

/* p_e: */

/**
 * p_e - Write a function that prints an error msg.
 *
 * @in: The struct.
 * @p: The string.
*/

void p_e(p_t *in, char *p)
{
	e_p(in->file_name);
	e_p(": ");
	p_d(in->l_count, STDERR_FILENO);
	e_p(": ");
	e_p(in->arguement_value[0]);
	e_p(": ");
	e_p(p);
}

/* p_d: */

/**
 * p_d - Write a function that prints int numbers.
 *
 * @a: The number.
 * @f: The file.
 *
 * Return: It will return (ct).
*/

int p_d(int a, int f)
{
	int index;
	int ct;
	int (*p_char)(char) = _putchar;
	unsigned int curr, t;

	ct = 0;
	/* If condition: */
	if (f == STDERR_FILENO)
	{
		p_char = e_p_char;
	}
	/* If condition: */
	if (a < 0)
	{
		t = -a;
		p_char('-');
		ct++;
	}
	else
		t = a;
	curr = t;
	/* For loop: */
	for (index = 1000000000; index > 1; index /= 10)
	{
		if (t / index)
		{
			p_char('0' + curr / index);
			ct++;
		}
		curr %= index;
	}
	p_char('0' + curr);
	ct++;
	return (ct);
}

/* conv_num: */

/**
 * conv_num - Write a function that converts the function.
 *
 * @v: The number.
 * @b: The base.
 * @fg: The flag.
 *
 * Return: It will return (s).
*/

char *conv_num(long int v, int b, int fg)
{
	char si;
	char *s;
	unsigned long number;
	static char *arr;
	static char bu[50];

	si = 0;
	number = v;
	/* If condition: */
	if (!(fg & CONV_UNSIGNED_NUMBERS) && v < 0)
	{
		number = -v;
		si = '-';
	}
	arr = fg & CONV_LCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	s = &bu[49];
	*s = '\0';
	/* Do while condition: */
	do	{
		*--s = arr[number % b];
		number /= b;
	} while (number != 0);
	/* If condition: */
	if (si)
	{
		*--s = si;
	}
	return (s);
}

/* delete_comm: */

/**
 * delete_comm - Write a function that replaces '#' -> '\0'.
 *
 * @b: The buffer.
*/

void delete_comm(char *b)
{
	int index;

	/* For loop: */
	for (index = 0; b[index] != '\0'; index++)
	{
		/* If condition: */
		if (b[index] == '#' && (!index || b[index - 1] == ' '))
		{
			b[index] = '\0';
			break;
		}
	}
}
