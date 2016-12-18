/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_t_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:40:16 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 16:50:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"
#include <stdlib.h>

static void	json_t_free_callback(t_json_t_value const *t, void *data)
{
	ASSERT(!"TODO");
}

static void	json_t_free_list(t_json_t_value const *t, void *data)
{
	uint32_t		i;
	t_vector *const	v = data;

	i = 0;
	if (g_json_t_free[t->list->type] != NULL)
		while (i < v->length)
			g_json_t_free[t->list->type](t->list, VECTOR_GET(*v, i++));
	ft_vclear(v);
}

static void	json_t_free_dict(t_json_t_value const *t, void *data)
{
	uint32_t		i;

	i = 0;
	while (i < t->dict.count)
	{
		ft_json_t_free(&t->dict.keys[i].val, data + t->dict.keys[i].offset);
		i++;
	}
}

static void	json_t_free_string(t_json_t_value const *t, void *data)
{
	free(*(t_sub**)data);
	(void)t;
}

void		(*const g_json_t_free[])(t_json_t_value const*, void*) = {
	[JSON_T_VAL_CALLBACK] = &json_t_free_callback,
	[JSON_T_VAL_LIST] = &json_t_free_list,
	[JSON_T_VAL_DICT] = &json_t_free_dict,
	[JSON_T_VAL_STRING] = &json_t_free_string,
	[JSON_T_VAL_INT] = NULL,
	[JSON_T_VAL_FLOAT] = NULL,
	[JSON_T_VAL_BOOL] = NULL,
};

void		ft_json_t_free(t_json_t_value const *t, void *data)
{
	if (g_json_t_free[t->type] != NULL)
		g_json_t_free[t->type](t, data);
}
