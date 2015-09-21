/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:01:27 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 12:28:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"

static t_bool	exec_expr(struct s_expr *expr)
{
	int				priority;
	struct s_expr	*tmp;

	priority = MAX_PRIORITY;
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
			}
			else
				tmp = tmp->next;
		}
		priority--;
	}
	return (true);
}

static t_bool	eval_subexpr(t_sub sub, int i, int *i_ptr, float *value)
{
	int				tmp;

	tmp = 1;
	while (++i < sub.length)
		if (sub.str[i] == '(')
			++tmp;
		else if (sub.str[i] == ')' && --tmp <= 0)
			break ;
	if (tmp != 0)
		return (false);
	tmp = *i_ptr;
	*i_ptr = i + 1;
	return (ft_evalexpr(SUB(sub.str + tmp + 1, i - tmp - 1), value));
}

static t_bool	eval_next(t_sub sub, int i, struct s_expr *prev,
		struct s_expr *first)
{
	struct s_expr	expr;

	expr.op = NULL;
	expr.next = NULL;
	prev->next = &expr;
	if (!eval_value(sub, &i, &(expr.n)))
		return (false);
	while (i < sub.length && IS(sub.str[i], IS_SPACE))
		++i;
	if (i >= sub.length)
		return (exec_expr(first));
	if (!parse_op(sub.str[i++], &expr))
		return (false);
	return (eval_next(sub, i, &expr, first));
}

t_bool			eval_value(t_sub sub, int *i_ptr, float *value)
{
	int				tmp;
	int				i;

	i = *i_ptr;
	while (i < sub.length && IS(sub.str[i], IS_SPACE))
		++i;
	*i_ptr = i;
	if (i < sub.length && sub.str[i] == '(')
		return (eval_subexpr(sub, i, i_ptr, value));
	if ((tmp = ft_subfloat(SUB(sub.str + i, sub.length - i), value)) > 0)
	{
		*i_ptr = i + tmp;
		return (true);
	}
	return (parse_func(sub, i_ptr, value));
}

t_bool			ft_evalexpr(t_sub expr, float *result)
{
	struct s_expr	first;

	first.n = 0.f;
	first.next = NULL;
	if (!parse_op('+', &first))
		return (false);
	if (eval_next(expr, 0, &first, &first))
	{
		*result = first.n;
		return (true);
	}
	return (false);
}
