/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_enum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:39:30 by juloo             #+#    #+#             */
/*   Updated: 2017/01/12 12:16:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

static void const	*get_value(t_json_t_enum const *e, t_sub name)
{
	uint32_t			i;

	i = 0;
	while (i < e->count)
	{
		if (SUB_EQU(e->values[i].name, name))
			return (e->values[i].data);
		i++;
	}
	return (NULL);
}

bool		json_t_parse_enum(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	void const	*enum_value;

	if (p->token != JSON_VALUE || p->value_type != JSON_VALUE_STRING)
		return (ft_json_fail(p, SUBC("Expecting string")));
	if ((enum_value = get_value(&t->_enum, JSON_VAL_STRING(p))) == NULL)
		return (ft_json_fail(p, SUBC("Unknown value")));
	memcpy(data, enum_value, t->_enum.data_size);
	return (true);
}
