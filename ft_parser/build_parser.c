/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 20:06:51 by juloo             #+#    #+#             */
/*   Updated: 2016/06/18 15:57:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/parser.h"
#include "ft/parser_def.h"

#include "p_parser.h"

/*
** TODO: allow NULL def->f
*/

static t_parser	*build(t_hmap *map, t_vector const *parsers,
					t_parser_def const *def)
{
	t_parser				*parser;

	ft_hmapputp(map, def->name, NULL);
	parser = ft_hmapput(map, def->name, NULL, sizeof(t_parser)).value;
	parser->data = def->data;
	parser->f = def->f;
	parser->token_map = TOKEN_MAP();
	parser->match = VECTOR(t_parser_match);
	parser->resolved = false;
	build_tokens(parser, def);
	build_inheritance(map, parser, parsers, def);
	return (parser);
}

t_parser		*get_parser(t_sub name, t_hmap *map, t_vector const *parsers)
{
	t_hpair				tmp;
	t_parser_def const	*def;
	uint32_t			i;

	if ((tmp = ft_hmapget(map, name)).key != NULL)
	{
		if (tmp.value == NULL)
			ft_dprintf(2, "Inherit loop: %ts%n", name);
		return (tmp.value);
	}
	i = 0;
	while (i < parsers->length)
	{
		def = VECTOR_GET(*parsers, i);
		if (def->name.length == name.length
			&& ft_memcmp(def->name.str, name.str, name.length) == 0)
			return (build(map, parsers, def));
		i++;
	}
	ft_dprintf(2, "Unknown parser: %ts%n", name);
	return (NULL);
}

bool			build_parser(t_hmap *dst, t_vector const *parsers)
{
	t_parser_def const *const	defs = parsers->data;
	t_parser					*p;
	uint32_t					i;

	i = 0;
	while (i < parsers->length)
	{
		if (ft_hmapget(dst, defs[i].name).key == NULL
			&& build(dst, parsers, defs + i) == NULL)
			return (false);
		i++;
	}
	i = 0;
	while (i < parsers->length)
	{
		p = ft_hmapget(dst, defs[i].name).value;
		if (!p->resolved && !resolve_subparsers(p, dst, parsers))
			ft_printf("Fail resolving dependencies for %ts%n", defs[i].name);
		i++;
	}
	return (true);
}
