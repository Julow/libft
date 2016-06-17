/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:52:39 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 19:10:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_parser.h"

static void		add_token(t_parser *parser, t_sub token_str,
					t_parser_token token)
{
	t_token_def		token_def;
	t_parser_token	*t;

	t = NEW(t_parser_token);
	*t = token;
	token_def.sub = token_str;
	token_def.data = t;
	ft_token_map(&parser->token_map, &token_def);
}

static void		add_match(t_parser *parser, t_sub pattern,
					t_parser_token token)
{
	t_parser_match	match;
	t_regex_err		err;

	if (!ft_rcompile(&match.regex, pattern, &err))
	{
		ft_printf("%ts: '%ts'\n%.*c^%n",
			err.str, pattern, err.str.length + 3, ' ');
		return ;
	}
	match.token = token;
	ft_vpush(&parser->match, &match, 1);
}

void			build_tokens(t_parser *parser, t_parser_def const *def)
{
	t_parser_def_t const	*token;
	uint32_t				i;

	i = 0;
	while (i < def->tokens.length)
	{
		token = VECTOR_GET(def->tokens, i);
		add_token(parser, token->token,
			(t_parser_token){token->data, V(token->parser), token->end});
		i++;
	}
	i = 0;
	while (i < def->match.length)
	{
		token = VECTOR_GET(def->match, i);
		add_match(parser, token->token,
			(t_parser_token){token->data, V(token->parser), token->end});
		i++;
	}
}
