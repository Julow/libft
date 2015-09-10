/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 01:30:25 by juloo             #+#    #+#             */
/*   Updated: 2015/09/10 02:06:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_var.h"
#include <stdio.h>

typedef struct	s_test
{
	double			a;
	char const		*c;
	int				d;
	char			b;
}				t_test;

t_test			test_var(t_var *var)
{
	return ((t_test){
		VAR_GET(*var, double),
		VAR_GET(*var, char const*),
		VAR_GET(*var, int),
		VAR_GET(*var, char),
	});
}

t_test			test_var_arg(int lol, ...)
{
	t_test			test;
	t_var			var;

	VAR_INIT_A(var, lol);
	test = test_var(&var);
	VAR_END(var);
	return (test);
}

t_test			test_var_struct(t_test *lol)
{
	t_test			test;
	t_var			var;

	VAR_INIT_S(var, lol);
	test = test_var(&var);
	VAR_END(var);
	return (test);
}

void			test_print(t_test *test)
{
	printf("test {%lf, %c, %llx, %d}\n", test->a, test->b, test->c, test->d);
}

int				main(void)
{
	t_test			test;

	test = (t_test){0.5, "lol", 'A', 42};
	test_print(&test);
	test = test_var_arg(0, test.a, test.c, test.d, test.b);
	test_print(&test);
	test = test_var_struct(&test);
	test_print(&test);
	return (0);
}
