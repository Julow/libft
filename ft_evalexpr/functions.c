/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 02:56:41 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_evalexpr.h"
#include <math.h>

static struct s_func	g_funcs[] = {
	{SUBC("cos"), cosf},
	{SUBC("sin"), sinf},
	{SUBC("tan"), tanf},
	{SUBC("acos"), acosf},
	{SUBC("asin"), asinf},
	{SUBC("atan"), atanf},
	{SUBC("exp"), expf},
	{SUBC("log"), logf},
	{SUBC("log2"), log2f},
	{SUBC("log10"), log10f},
	{SUBC("sqrt"), sqrtf},
	{SUBC("ceil"), ceilf},
	{SUBC("floor"), floorf},
	{SUBC("round"), roundf},
	{SUBC("abs"), fabsf},
	{SUB(NULL, 0), NULL}
};

bool			parse_func(t_sub sub, int *i_ptr, float *value)
{
	int				len;
	int				i;

	len = *i_ptr;
	while (len < sub.length && IS(sub.str[len], IS_WORD))
		++len;
	len -= *i_ptr;
	if (len <= 0)
		return (false);
	i = -1;
	while (g_funcs[++i].f != NULL)
		if (g_funcs[i].name.length == len
			&& ft_memcmp(g_funcs[i].name.str, sub.str + *i_ptr, len) == 0)
		{
			*i_ptr += len;
			if (!eval_value(sub, i_ptr, value))
				return (false);
			*value = g_funcs[i].f(*value);
			return (true);
		}
	return (false);
}
