/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:52:39 by jaguillo          #+#    #+#             */
/*   Updated: 2016/07/28 17:45:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_parser.h"

void			add_token(t_parser *parser, t_sub token_str,
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
}
