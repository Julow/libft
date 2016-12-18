/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_t_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:26:42 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 18:10:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

bool		(*const g_json_t_parse[])(t_json_parser*, t_json_t_value const*, void*) = {
	[JSON_T_VAL_CALLBACK] = json_t_parse_callback,
	[JSON_T_VAL_LIST] = json_t_parse_list,
	[JSON_T_VAL_DICT] = json_t_parse_dict,
	[JSON_T_VAL_FIXED_LIST] = json_t_parse_fixed_list,
	[JSON_T_VAL_STRING] = json_t_parse_string,
	[JSON_T_VAL_INT] = json_t_parse_int,
	[JSON_T_VAL_FLOAT] = json_t_parse_float,
	[JSON_T_VAL_BOOL] = json_t_parse_bool,
};

bool		ft_json_parse(t_json_parser *p, t_json_t_value const *t, void *data)
{
	if (!ft_json_next(p))
		return (json_parse_error(p, SUBC("Unexpected EOF")), false);
	return (g_json_t_parse[t->type](p, t, data));
}
