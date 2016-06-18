/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:18:26 by juloo             #+#    #+#             */
/*   Updated: 2016/06/18 15:57:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "p_parser.h"

static bool		exec_match_match(t_parse_data *p, uint32_t offset,
					t_rmatch const *rmatch, t_parser_token const *token)
{
	if (offset > 0)
	{
		p->t.end -= p->t.token.length - offset;
		p->t.token.length = offset;
		p->token = p->t.token;
		p->token_data = NULL;
		return (true);
	}
	p->t.end -= p->t.token.length - rmatch->match.length;
	p->t.token.length = rmatch->match.length;
	p->t.token_data = token;
	return (exec_token(p));
}

bool			exec_token(t_parse_data *p)
{
	t_parser_token const *const	t = p->t.token_data;

	p->token = p->t.token;
	p->token_data = t->data;
	if (t->parser != NULL)
	{
		if (!ft_parse(p, t->parser) || t->end)
			return (false);
		return (ft_parse_token(p));
	}
	return (!t->end);
}

bool			exec_match(t_parse_data *p)
{
	t_parser_match	*m;
	t_vec2u			i;
	t_rmatch		rmatch;

	rmatch = C(t_rmatch, p->t.token, SUB_START(p->t.token), NULL, 0, 0,
		(p->flags & PARSE_F_FIRST) ? 0 : RMATCH_F_NBOL);
	i = VEC2U(0, 0);
	if (p->frame->parser->match.length > 0)
		while (true)
		{
			m = VECTOR_GET(p->frame->parser->match, i.x);
			rmatch.match = SUB(p->t.token.str + i.y, 0);
			if (ft_rmatch(&rmatch, &m->regex))
				return (exec_match_match(p, i.y, &rmatch, &m->token));
			if (++i.x < p->frame->parser->match.length)
				continue ;
			rmatch.flags &= ~RMATCH_F_NBOL;
			if (++i.y >= (p->t.token.length - 1))
				break ;
			i.x = 0;
		}
	p->token = p->t.token;
	p->token_data = NULL;
	return (true);
}
