/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparser_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:13:38 by jaguillo          #+#    #+#             */
/*   Updated: 2016/07/28 18:20:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_parser.h"

static bool		resolve_token_subparsers(t_token_def *def,
					t_subparser_resolver *s)
{
	t_parser_token	*t;

	t = def->data;
	if (t->parser != NULL)
	{
		if ((t->parser = get_parser(ft_sub((char const*)t->parser, 0, -1),
			s->map, s->parsers)) == NULL)
			return (false);
	}
	return (true);
}

bool			resolve_subparsers(t_parser *parser, t_hmap *map,
					t_vector const *parsers)
{
	t_subparser_resolver	s;

	s = (t_subparser_resolver){parser, map, parsers};
	if (!ft_bst_iter(&parser->token_map.tokens, &resolve_token_subparsers, &s))
		return (false);
	return (true);
}
