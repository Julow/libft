/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_except.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:37:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/21 14:37:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

static t_sub const	g_json_except_err[] = {
	[JSON_BEGIN_DICT] = SUBC("Unexpected token: Expecting '['"),
	[JSON_BEGIN_LIST] = SUBC("Unexpected token: Expecting '{'"),
	[JSON_END] = SUBC("Unexpected token: Expecting end"),
	[JSON_VALUE] = SUBC("Unexpected token: Expecting value"),
	[JSON_ERROR] = SUB0(),
	[JSON_EOF] = SUBC("Unexpected token: Expecting EOF"),
};

static t_sub const	g_json_except_value_err[] = {
	[JSON_VALUE_STRING] = SUBC("Invalid value: Expecting string"),
	[JSON_VALUE_INT] = SUBC("Invalid value: Expecting int"),
	[JSON_VALUE_FLOAT] = SUBC("Invalid value: Expecting float"),
	[JSON_VALUE_BOOL] = SUBC("Invalid value: Expecting bool"),
	[JSON_VALUE_NULL] = SUBC("Invalid value: Expecting null"),
};

bool		ft_json_except(t_json_parser *p, t_json_token except)
{
	ft_json_next(p);
	if (p->token == JSON_ERROR)
		return (false);
	if (p->token != except)
		return (ft_json_fail(p, g_json_except_err[except]));
	return (true);
}

bool		ft_json_except_value(t_json_parser *p, t_json_value_t except)
{
	if (!ft_json_except(p, JSON_VALUE))
		return (false);
	if (p->value_type != except)
		return (ft_json_fail(p, g_json_except_value_err[except]));
	return (true);
}
