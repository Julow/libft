/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 00:31:05 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:44:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_evalexpr.h"
#include <math.h>

static struct s_op	g_ops[] = {
	{'+', 1, &op_plus},
	{'-', 1, &op_moins},
	{'*', 2, &op_mult},
	{'/', 2, &op_div},
	{'%', 2, &fmodf},
	{'^', 3, &powf},
	{'\0', 0, NULL}
};

t_bool			parse_op(char c, struct s_expr *expr)
{
	int				i;

	i = -1;
	while (g_ops[++i].symbol != '\0')
		if (g_ops[i].symbol == c)
		{
			expr->op = g_ops + i;
			return (true);
		}
	return (false);
}
