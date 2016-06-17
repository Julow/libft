/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 18:49:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_parser.h"

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
