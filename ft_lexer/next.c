/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:22:23 by juloo             #+#    #+#             */
/*   Updated: 2016/09/05 17:33:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

static void		lexer_assert(t_lexer const *l) // TODO: tmp
{
	ASSERT(l->state != NULL);
	ASSERT(l->t.token_map == l->state->token_map);
	ASSERT(!l->should_push);
	ASSERT(!l->should_pop);
}

bool			ft_lexer_next(t_lexer *l)
{
	t_lexer_token const	*token;

	lexer_assert(l);
	if (!ft_tokenize(&l->t))
	{
		l->token = NULL;
		l->eof = l->t.eof;
		return (false);
	}
	if ((token = l->t.token) == NULL)
	{
		l->token = NULL;
		return (true);
	}
	l->token = token->data;
	if (token->pop)
		l->should_pop = true;
	if (token->push != NULL)
		l->should_push = true;
	return (true);
}

bool			ft_lexer_ahead(t_lexer *l, t_sub *s, void const **data)
{
	t_lexer_token const	*token;

	lexer_assert(l);
	if (!ft_tokenize_ahead(&l->t, s, V(&token)))
	{
		if (data != NULL)
			*data = NULL;
		return (false);
	}
	if (data != NULL)
		*data = (token == NULL) ? NULL : token->data;
	return (true);
}
