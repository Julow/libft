/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 00:31:05 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 03:01:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"
#include <math.h>

static float	op_plus(float a, float b);
static float	op_moins(float a, float b);
static float	op_mult(float a, float b);
static float	op_div(float a, float b);

static t_op		g_ops[] = {
	{'+', 1, &op_plus},
	{'-', 1, &op_moins},
	{'*', 2, &op_mult},
	{'/', 2, &op_div},
	{'%', 2, &fmodf},
	{'^', 3, &powf},
	{'\0', 0, NULL}
};

static float	op_plus(float a, float b)
{
	return (a + b);
}

static float	op_moins(float a, float b)
{
	return (a - b);
}

static float	op_mult(float a, float b)
{
	return (a * b);
}

static float	op_div(float a, float b)
{
	return (a / b);
}

t_bool			parse_op(char c, t_expr *expr)
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
