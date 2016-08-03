/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:22:23 by juloo             #+#    #+#             */
/*   Updated: 2016/08/04 01:00:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

static void		lexer_assert(t_lexer const *l) // TODO: tmp
{
	t_lexer_state const *const	last_state = LAST_STATE(*l);

	ASSERT(l->states.length > 0);
	ASSERT(l->t.token_map == &last_state->token_map);
}

bool			ft_lexer_next(t_lexer *l)
{
	t_lexer_token const	*token;

	lexer_assert(l);
	if (!ft_tokenize(&l->t))
	{
		l->token = NULL;
		l->eof = true;
		return (false);
	}
	if ((token = l->t.token_data) == NULL)
	{
		l->token = NULL;
		return (true);
	}
	l->token = token->data;
	if (token->pop)
		ft_lexer_pop(l);
	if (token->push != NULL)
		ft_lexer_push(l, token->push);
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
