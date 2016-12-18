/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:29:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 16:43:04 by jaguillo         ###   ########.fr       */
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
		return (json_parse_error(p, SUBC("Expecting list")), false);
	*(t_vector*)data = (t_vector){NULL, 0, 0, ft_json_t_sizeof(t->list)};
	while (ft_json_next(p))
	{
		if (p->token == JSON_END)
			return (true);
		if (!g_json_t_parse[t->list->type](p, t->list, ft_vpush(data, NULL, 1)))
		{
			free_list(t->list, data);
			return (false);
		}
	}
	return (false);
}
