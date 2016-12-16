/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:49:15 by juloo             #+#    #+#             */
/*   Updated: 2016/12/15 16:44:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

static bool			get_bool_val(t_sub val, bool *dst)
{
	if (SUB_EQU(SUBC("true"), val))
		*dst = true;
	else if (SUB_EQU(SUBC("false"), val))
		*dst = false;
	else
		return (false);
	return (true);
}

static bool			get_identifier(t_json_parser *p)
{
	t_sub const			val = JSON_VAL_STRING(p);
	t_json_value_t		val_t;

	if (get_bool_val(val, &p->val_bool))
		val_t = JSON_VALUE_BOOL;
	else if (SUB_EQU(SUBC("null"), val))
		val_t = JSON_VALUE_NULL;
	else if (ft_subto_int(val, &p->val_int) == val.length)
		val_t = JSON_VALUE_INT;
	else if (ft_subto_float(val, &p->val_float) == val.length)
		val_t = JSON_VALUE_FLOAT;
	else
		return (json_parse_error(p, SUBC("Invalid value")), false);
	p->value_type = val_t;
	return (true);
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
		return (json_parse_error(p, SUBC("Unexpected EOF")));
	return (json_parse_error(p, SUBC("Syntax error: Expecting value")));
}
