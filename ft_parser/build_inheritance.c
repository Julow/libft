/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_inheritance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:09:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/18 15:53:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_parser.h"

static bool		has_dupplicated_token(void *env,
					t_token_def const *token, t_sub const *name)
{
	if (SUB_EQU(token->sub, *name))
		return (false);
	return (true);
	(void)env;
}

static bool		inherit_tokens(t_token_def const *token, t_parser *parser)
{
	t_parser_token *const	p_token = token->data;

	if (ft_bst_getall(&parser->token_map.tokens, &token->sub,
			&has_dupplicated_token, NULL))
		add_token(parser, token->sub, *p_token);
	return (true);
}

/*
** TODO: dup regex
*/

static void		inherit_match(t_parser *parser, t_parser const *parent)
{
	uint32_t				i;
	t_parser_match			match;
	t_parser_match const	*m;

	i = 0;
	while (i < parent->match.length)
	{
		m = VECTOR_GET(parent->match, i);
		match.regex = m->regex;
		match.token = (t_parser_token){m->token.data, m->token.parser, false};
		ft_vpush(&parser->match, &match, 1);
		i++;
	}
}

void			build_inheritance(t_hmap *map, t_parser *parser,
					t_vector const *parsers, t_parser_def const *def)
{
	t_parser				*parent;
	uint32_t				i;

	i = 0;
	while (i < def->parents.length)
	{
		if ((parent = get_parser(ft_sub(*(void**)VECTOR_GET(def->parents, i++),
					0, -1), map, parsers)) == NULL)
			continue ;
		ft_bst_iter(&parent->token_map.tokens, &inherit_tokens, parser);
		inherit_match(parser, parent);
	}
}
