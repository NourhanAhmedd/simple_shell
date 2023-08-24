#include "s_shell.h"

/* main: */

/**
 * main - The entry point.
 *
 * @argument_c: The argument count.
 * @argument_v: The argument vector.
 *
 * Return: It will return 0 (success) or 1 (error).
*/

int main(int argument_c, char **argument_v)
{
	int p;
	p_t in[] = { INFO_NUMBERS };

	p = 2;
	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (p)
		: "r" (p));

	if (argument_c == 2)
	{
		p = open(argument_v[1], O_RDONLY);
		if (p == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				e_p(argument_v[0]);
				e_p(": 0: Can't open ");
				e_p(argument_v[1]);
				e_p_char('\n');
				e_p_char(BUFFER_F);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		in->read_line_input = p;
	}
	p_elist(in);
	r_hist(in);
	f_hsh(in, argument_v);
	return (EXIT_SUCCESS);
}
