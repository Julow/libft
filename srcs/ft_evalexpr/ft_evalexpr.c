/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:01:27 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 02:54:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"

t_op			g_ops[] = {
	{'+', 1, &op_plus},
	{'-', 1, &op_moins},
	{'*', 2, &op_mult},
	{'/', 2, &op_div},
	{'\0', 0, NULL}
};

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

// DEBUG
#include <stdio.h>

void			print_expr(t_expr *expr)
{
	while (expr != NULL)
	{
		if (expr->op == NULL)
			printf("%f\n", expr->n);
		else
			printf("%f %c ", expr->n, expr->op->symbol);
		expr = expr->next;
	}
}
// -

t_bool			exec_expr(t_expr *expr)
{
	int				priority;
	t_expr			*tmp;

	print_expr(expr);
	priority = 2;
	while (priority >= 1)
	{
		tmp = expr;
		while (tmp != NULL && tmp->next != NULL)
		{
			if (tmp->op->priority == priority)
			{
				tmp->n = tmp->op->f(tmp->n, tmp->next->n);
				tmp->op = tmp->next->op;
				tmp->next = tmp->next->next;
				print_expr(expr);
			}
			else
				tmp = tmp->next;
		}
		priority--;
	}
	return (true);
}

t_bool			eval_value(t_sub sub, int *i_ptr, float *value)
{
	int				tmp;
	int				i;

	i = *i_ptr;
	while (i < sub.length && IS(sub.str[i], IS_SPACE))
		++i;
	if (i < sub.length && sub.str[i] == '(')
	{
		tmp = i;
		while (tmp < sub.length && sub.str[tmp] != ')')
			++tmp;
		if (tmp >= sub.length)
			return (false);
		*i_ptr = tmp + 1;
		tmp -= i;
		return (ft_evalexpr(SUB(sub.str + i + 1, tmp - 1), value));
	}
	if ((tmp = ft_subfloat(SUB(sub.str + i, sub.length - i), value)) > 0)
	{
		i += tmp;
		*i_ptr = i;
		return (true);
	}
	return (false); // TODO functions
}

t_bool			eval_next(t_sub sub, int i, t_expr *prev, t_expr *first)
{
	t_expr			expr;

	expr.op = NULL;
	expr.next = NULL;
	prev->next = &expr;
	if (!eval_value(sub, &i, &(expr.n)))
		return (printf("Invalid value\n"), false);
	while (i < sub.length && IS(sub.str[i], IS_SPACE))
		++i;
	if (i >= sub.length)
		return (exec_expr(first));
	if (!parse_op(sub.str[i++], &expr))
		return (false);
	return (eval_next(sub, i, &expr, first));
}

t_bool			ft_evalexpr(t_sub expr, float *result)
{
	t_expr			first;

	first.n = 0.f;
	first.op = &(t_op){'+', 1, &op_plus};
	first.next = NULL;
	if (eval_next(expr, 0, &first, &first))
	{
		*result = first.n;
		return (true);
	}
	return (false);
}
