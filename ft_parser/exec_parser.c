/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:18:26 by juloo             #+#    #+#             */
/*   Updated: 2016/03/07 14:53:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/parser.h"

static bool		exec_token(t_parse_data *p)
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

static bool		exec_match(t_parse_data *p)
{
	t_parser_match	*m;
	uint32_t		offset;
	uint32_t		i;
	t_rmatch		rmatch;

	rmatch = C(t_rmatch, p->t.token, SUB_START(p->t.token), NULL, 0, 0,
		(p->flags & PARSE_F_FIRST) ? 0 : RMATCH_F_NBOL);
	i = 0;
	offset = 0;
	if (p->frame->parser->match.length > 0)
		while (true)
		{
			m = VECTOR_GET(p->frame->parser->match, i);
			rmatch.match = SUB(p->t.token.str + offset, 0);
			if (ft_rmatch(&rmatch, &m->regex))
			{
				if (offset > 0)
				{
					p->t.end -= p->t.token.length - offset;
					p->t.token.length = offset;
					break ;
				}
				p->t.end -= p->t.token.length - rmatch.match.length;
				p->t.token.length = rmatch.match.length;
				p->t.token_data = &m->token;
				return (exec_token(p));
			}
			if (++i >= p->frame->parser->match.length)
			{
				rmatch.flags &= ~RMATCH_F_NBOL;
				if (++offset >= (p->t.token.length - 1))
					break ;
				i = 0;
			}
		}
	p->token = p->t.token;
	p->token_data = NULL;
	return (true);
}

bool			ft_parse(t_parse_data *p, t_parser const *parser)
{
	t_parse_frame			frame;
	bool					ret;

	p->flags |= PARSE_F_FIRST | _PARSE_F_FIRST;
	frame = (t_parse_frame){parser, NULL, p->frame};
	p->frame = &frame;
	p->t.token_map = &parser->token_map;
	ret = parser->f(p);
	p->t.token_map = (frame.prev == NULL) ?
		NULL : &frame.prev->parser->token_map;
	p->frame = frame.prev;
	return (ret);
}

bool			ft_parse_token(t_parse_data *p)
{
	if (PARSE_ERROR(p))
		return (false);
	if (p->flags & _PARSE_F_FIRST)
		p->flags &= ~_PARSE_F_FIRST;
	else if (p->flags & PARSE_F_FIRST)
		p->flags &= ~PARSE_F_FIRST;
	if (!ft_tokenize(&p->t))
	{
		p->token = SUB0();
		p->token_data = NULL;
		p->flags |= PARSE_F_EOF;
		return (false);
	}
	if (p->t.token_data == NULL)
		return (exec_match(p));
	return (exec_token(p));
}

bool			ft_parse_error(t_parse_data *p, t_sub err)
{
	p->token = err;
	p->flags |= PARSE_F_ERROR;
	return (false);
}
