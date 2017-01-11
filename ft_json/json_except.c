/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_except.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:37:02 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/09 13:03:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

static t_sub const	g_json_except_err[] = {
	[JSON_BEGIN_DICT] = SUBC("'{'"),
	[JSON_BEGIN_LIST] = SUBC("'['"),
	[JSON_END] = SUBC("end"),
	[JSON_VALUE] = SUBC("value"),
	[JSON_ERROR] = SUB0(),
	[JSON_EOF] = SUBC("EOF"),
};

static t_sub const	g_json_except_value_err[] = {
	[JSON_VALUE_STRING] = SUBC("string"),
	[JSON_VALUE_INT] = SUBC("int"),
	[JSON_VALUE_FLOAT] = SUBC("float"),
	[JSON_VALUE_BOOL] = SUBC("bool"),
	[JSON_VALUE_NULL] = SUBC("null"),
};

bool		ft_json_except(t_json_parser *p, t_json_token except)
{
	t_json_token	tmp;

	ft_json_next(p);
	if (p->token == JSON_ERROR)
		return (false);
	if (p->token != except)
	{
		tmp = p->token;
		ft_json_fail(p, SUBC("Unexpected token: Expecting "));
		ft_dstradd(&p->buff, g_json_except_err[except]);
		ft_dstradd(&p->buff, SUBC(" got "));
		ft_dstradd(&p->buff, g_json_except_err[tmp]);
		return (false);
	}
	return (true);
}

bool		ft_json_except_value(t_json_parser *p, t_json_value_t except)
{
	t_json_value_t	tmp;

	if (!ft_json_except(p, JSON_VALUE))
		return (false);
	if (p->value_type != except)
	{
		tmp = p->value_type;
		ft_json_fail(p, SUBC("Invalid value: Expecting "));
		ft_dstradd(&p->buff, g_json_except_value_err[except]);
		ft_dstradd(&p->buff, SUBC("got"));
		ft_dstradd(&p->buff, g_json_except_value_err[tmp]);
		return (false);
	}
	return (true);
}
