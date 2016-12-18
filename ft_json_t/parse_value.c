/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:27:15 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 16:43:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

bool		json_t_parse_callback(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	return (ASSERT(!"TODO"));
}

bool		json_t_parse_string(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	t_sub		val_string;
	t_sub		*value;

	if (p->token != JSON_VALUE && p->value_type != JSON_VALUE_STRING)
		return (json_parse_error(p, SUBC("Expecting string")), false);
	val_string = JSON_VAL_STRING(p);
	value = MALLOC(sizeof(t_sub) + val_string.length);
	*value = SUB(ENDOF(value), val_string.length);
	ft_memcpy(ENDOF(value), val_string.str, val_string.length);
	*(t_sub**)data = value;
	return (true);
	(void)t;
}

bool		json_t_parse_int(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	if (p->token != JSON_VALUE && p->value_type != JSON_VALUE_INT)
		return (json_parse_error(p, SUBC("Expecting int")), false);
	*(int32_t*)data = p->val_int;
	return (true);
	(void)t;
}

bool		json_t_parse_float(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	if (p->token != JSON_VALUE && p->value_type != JSON_VALUE_FLOAT)
		return (json_parse_error(p, SUBC("Expecting float")), false);
	*(float*)data = p->val_float;
	return (true);
	(void)t;
}

bool		json_t_parse_bool(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	if (p->token != JSON_VALUE && p->value_type != JSON_VALUE_BOOL)
		return (json_parse_error(p, SUBC("Expecting bool")), false);
	*(bool*)data = p->val_bool;
	return (true);
	(void)t;
}
