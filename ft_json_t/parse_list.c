/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:29:37 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/23 18:04:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

static void	free_list(t_json_t_value const *t, t_vector *lst)
{
	uint32_t	i;

	i = 0;
	while (i < lst->length)
		ft_json_t_free(t, VECTOR_GET(*lst, i++));
	ft_vclear(lst);
}

bool		json_t_parse_list(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	if (p->token != JSON_BEGIN_LIST)
		return (ft_json_fail(p, SUBC("Expecting list")));
	*(t_vector*)data = (t_vector){NULL, 0, 0, ft_json_t_sizeof(t->list)};
	while (ft_json_next(p))
	{
		if (p->token == JSON_END)
			return (true);
		if (!g_json_t_parse[t->list->type](p, t->list, ft_vpush(data, NULL, 1)))
		{
			((t_vector*)data)->length--;
			break ;
		}
	}
	free_list(t->list, data);
	return (false);
}

static void	free_tuple(t_json_t_tuple const *t, void *data, uint32_t end)
{
	uint32_t			i;

	i = 0;
	while (i < end)
	{
		ft_json_t_free(t->items[i].val, data + t->items[i].offset);
		i++;
	}
}

bool		json_t_parse_tuple(t_json_parser *p,
				t_json_t_value const *t, void *data)
{
	uint32_t			i;
	t_json_t_item const	*item;

	if (p->token != JSON_BEGIN_LIST)
		return (ft_json_fail(p, SUBC("Expecting list")));
	i = 0;
	while (ft_json_next(p))
	{
		if (i >= t->tuple.count)
		{
			if (p->token == JSON_END)
				return (true);
			ft_json_fail(p, SUBC("Too many values in array"));
			break ;
		}
		if (p->token == JSON_END)
		{
			ft_json_fail(p, SUBC("Incomplete value"));
			break ;
		}
		item = &t->tuple.items[i];
		if (!g_json_t_parse[item->val->type](p, item->val, data + item->offset))
			break ;
		i++;
	}
	free_tuple(&t->tuple, data, i);
	return (false);
}
