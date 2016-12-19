/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:27:15 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 18:36:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

bool		json_t_parse_callback(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	return (t->callback.f(p, data, t->callback.param));
}

bool		json_t_parse_string(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	t_sub		val_string;
	t_sub		*value;

	if (p->token != JSON_VALUE || p->value_type != JSON_VALUE_STRING)
		return (ft_json_fail(p, SUBC("Expecting string")));
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
	if (p->token != JSON_VALUE || p->value_type != JSON_VALUE_INT)
		return (ft_json_fail(p, SUBC("Expecting int")));
	*(int32_t*)data = p->val_int;
	return (true);
	(void)t;
}

bool		json_t_parse_float(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	if (p->token != JSON_VALUE || (p->value_type != JSON_VALUE_FLOAT
				&& p->value_type != JSON_VALUE_INT))
		return (ft_json_fail(p, SUBC("Expecting float")));
	*(float*)data = JSON_VAL_NUMBER(p);
	return (true);
	(void)t;
}

bool		json_t_parse_bool(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	if (p->token != JSON_VALUE || p->value_type != JSON_VALUE_BOOL)
		return (ft_json_fail(p, SUBC("Expecting bool")));
	*(bool*)data = p->val_bool;
	return (true);
	(void)t;
}
