/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:50:51 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 19:05:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

void			ft_lexer_push(t_lexer *l, t_lexer_state const **save)
{
	t_lexer_token const *const	t = l->t.token;

	ASSERT(l->should_push, "should_push not set");
	ASSERT(t->push != NULL);
	l->should_push = false;
	*save = l->state;
	l->state = t->push;
	l->t.token_map = t->push->token_map;
}

void			ft_lexer_pop(t_lexer *l, t_lexer_state const *prev)
{
	l->should_pop = false;
	l->state = prev;
	l->t.token_map = (prev == NULL) ? NULL : prev->token_map;
}

void			ft_lexer_destroy(t_lexer *l)
{
	ft_tokenizer_reset(&l->t, true);
}
