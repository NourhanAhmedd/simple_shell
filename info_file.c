#include "s_shell.h"

/* c_inf: */

/**
 * c_inf - Write a function that initializes the structure.
 * @in: The address.
*/

void c_inf(p_t *in)
{
	in->arguement = NULL;
	in->arguement_value = NULL;
	in->path_pointer = NULL;
	in->arguement_c = 0;
}

/* s_inf: */

/**
 * s_inf - Write a function that initializes the structure.
 * @in: The address.
 * @a_v: The argument value.
*/

void s_inf(p_t *in, char **a_v)
{
	int index;

	index = 0;
	in->file_name = a_v[0];
	/* If condition: */
	if (in->arguement)
	{
		in->arguement_value = st1(in->arguement, " \t");
		/* If condition: */
		if (!in->arguement_value)
		{
			in->arguement_value = malloc(sizeof(char *) * 2);
			/* If condition: */
			if (in->arguement_value)
			{
				in->arguement_value[0] = s_dup(in->arguement);
				in->arguement_value[1] = NULL;
			}
		}
		/* For loop: */
		for (index = 0; in->arguement_value && in->arguement_value[index]; index++)
			;
		in->arguement_c = index;
		rep_ali(in);
		rep_v(in);
	}
}

/* f_inf: */

/**
 * f_inf - Write a function that frees the struct.
 * @in: The address.
 * @t: True.
*/

void f_inf(p_t *in, int t)
{
	file_free(in->arguement_value);
	in->arguement_value = NULL;
	in->path_pointer = NULL;
	/* If condition: */
	if (t)
	{
		if (!in->cmd_b)
		{
			free(in->arguement);
		}
		if (in->environ_linked_list)
		{
			li_free(&(in->environ_linked_list));
		}
		if (in->hist_n)
		{
			li_free(&(in->hist_n));
		}
		if (in->al_n)
		{
			li_free(&(in->al_n));
		}
		file_free(in->environ_copy);
			in->environ_copy = NULL;
		free_b((void **)in->cmd_b);
		if (in->read_line_input > 2)
		{
			close(in->read_line_input);
		}
		_putchar(BUFFER_F);
	}
}
