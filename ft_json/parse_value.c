/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:49:15 by juloo             #+#    #+#             */
/*   Updated: 2016/12/14 23:52:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

static bool			get_identifier(t_json_parser *p)
{
	t_sub const			val = JSON_VAL_STRING(p);

	if (SUB_EQU(SUBC("false"), val))
	{
		p->val_bool = false;
		p->value_type = JSON_VALUE_BOOL;
		return (true);
	}
	if (SUB_EQU(SUBC("true"), val))
	{
		p->val_bool = true;
		p->value_type = JSON_VALUE_BOOL;
		return (true);
	}
	if (SUB_EQU(SUBC("null"), val))
	{
		p->value_type = JSON_VALUE_NULL;
		return (true);
	}
	TRACE("TODO: json number");
	p->buff.length = p->state_len;
	ft_dstradd(&p->buff, SUBC("Invalid value"));
	return (false);
}

t_json_token	json_parse_value(t_json_parser *p, t_json_p_token t)
{
	if (t == JSON_P_BRACE_OPEN)
		return (JSON_BEGIN_DICT);
	if (t == JSON_P_SQUARE_OPEN)
		return (JSON_BEGIN_LIST);
	if (t == JSON_P_STRING)
	{
		p->value_type = JSON_VALUE_STRING;
		return (JSON_VALUE);
	}
	if (t == JSON_P_IDENTIFIER)
		return (get_identifier(p) ? JSON_VALUE : JSON_ERROR);
	if (t == JSON_P_ERROR)
		return (JSON_ERROR);
	if (t == JSON_P_EOF)
		return (json_parse_error(p, SUBC("Unexpected EOF")), JSON_ERROR);
	json_parse_error(p, SUBC("Syntax error: Expecting value"));
	return (JSON_ERROR);
}
