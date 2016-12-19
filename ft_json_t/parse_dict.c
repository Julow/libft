/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:28:23 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 18:09:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_t.h"

static uint32_t	get_key(t_json_t_dict const *dict, t_sub name) // TODO: improve
{
	uint32_t			i;

	i = 0;
	while (i < dict->count)
	{
		if (SUB_EQU(dict->keys[i].key, name))
			break ;
		i++;
	}
	return (i);
}

static bool		check_required_keys(t_json_parser *p, t_json_t_dict const *dict,
					bool const *set)
{
	uint32_t			i;

	i = 0;
	while (i < dict->count)
	{
		if (!set[i])
			return (ft_json_fail(p, SUBC("Missing required key")));
		i++;
	}
	return (true);
}

static void		free_dict(t_json_t_dict const *dict, bool const *set, void *data)
{
	uint32_t		i;

	i = 0;
	while (i < dict->count)
	{
		if (set[i])
			ft_json_t_free(dict->keys[i].val, data + dict->keys[i].offset);
		i++;
	}
}

bool			json_t_parse_dict(t_json_parser *p,
					t_json_t_value const *t, void *data)
{
	bool				keys_set[t->dict.count];
	t_json_t_key const	*key;
	uint32_t			i;

	if (p->token != JSON_BEGIN_DICT)
		return (ft_json_fail(p, SUBC("Expecting dict")));
	ft_bzero(keys_set, sizeof(keys_set));
	while (ft_json_next(p))
	{
		if (p->token == JSON_END)
			return (check_required_keys(p, &t->dict, keys_set));
		if ((i = get_key(&t->dict, JSON_KEY_STRING(p))) >= t->dict.count)
			return (ft_json_fail(p, SUBC("Unknown key")));
		key = &t->dict.keys[i];
		if (keys_set[i])
			return (ft_json_fail(p, SUBC("Dupplicated key")));
		keys_set[i] = true;
		if (!g_json_t_parse[key->val->type](p, key->val, data + key->offset))
			break ;
	}
	free_dict(&t->dict, keys_set, data);
	return (false);
}
