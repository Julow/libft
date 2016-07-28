/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/07/28 17:56:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_parser.h"

bool			ft_parse(t_parse_data *p, t_parser const *parser, void *param)
{
	t_token_map const *const	prev_token_map = p->t.token_map;
	bool						r;

	p->flags |= PARSE_F_FIRST | _PARSE_F_FIRST;
	p->t.token_map = &parser->token_map;
	r = parser->f(p, parser->data, param);
	p->t.token_map = prev_token_map;
	return (r);
}

bool			ft_parse_token(t_parse_data *p, void *param)
{
	t_parser_token const	*t;

	if (PARSE_ERROR(p))
		return (false);
	if (p->flags & _PARSE_F_FIRST)
		p->flags &= ~_PARSE_F_FIRST;
	else if (p->flags & PARSE_F_FIRST)
		p->flags &= ~PARSE_F_FIRST;
	p->token_data = NULL;
	if (!ft_tokenize(&p->t))
	{
		p->token = SUB0();
		p->flags |= PARSE_F_EOF;
		return (false);
	}
	p->token = p->t.token;
	if ((t = p->t.token_data) == NULL)
		return (true);
	if (t->parser != NULL && !ft_parse(p, t->parser, param))
		return (false);
	p->token_data = t->data;
	return (!t->end);
}

bool			ft_parse_error(t_parse_data *p)
{
	p->flags |= PARSE_F_ERROR;
	return (false);
}
