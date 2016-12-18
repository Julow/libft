/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_t_sizeof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:25:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 14:25:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

static uint32_t const	g_json_t_sizeof[] = {
	[JSON_T_VAL_CALLBACK] = 0,
	[JSON_T_VAL_LIST] = sizeof(t_vector),
	[JSON_T_VAL_DICT] = 0,
	[JSON_T_VAL_STRING] = sizeof(t_sub*),
	[JSON_T_VAL_INT] = sizeof(int32_t),
	[JSON_T_VAL_FLOAT] = sizeof(float),
	[JSON_T_VAL_BOOL] = sizeof(bool),
};

uint32_t	ft_json_t_sizeof(t_json_t_value const *t)
{
	if (t->type == JSON_T_VAL_CALLBACK)
		return (t->callback.data_size);
	if (t->type == JSON_T_VAL_DICT)
		return (t->dict.data_size);
	return (g_json_t_sizeof[t->type]);
}
