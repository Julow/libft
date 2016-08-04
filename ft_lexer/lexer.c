/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:50:51 by juloo             #+#    #+#             */
/*   Updated: 2016/08/04 20:36:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

void			ft_lexer_init(t_in *in, t_lexer_state const *s, t_lexer *dst)
{
	*dst = (t_lexer){
		TOKENIZER(in, &s->token_map),
		VECTOR(t_lexer_state const*),
		NULL,
		false, false, false
	};
	ft_vpush(&dst->states, &s, 1);
}

void			ft_lexer_push(t_lexer *l)
{
	t_lexer_token const *const	t = l->t.token_data;

	ASSERT(l->should_push, "should_push not set");
	ASSERT(t->push != NULL);
	l->should_push = false;
	ft_vpush(&l->states, &t->push, 1);
	l->t.token_map = &t->push->token_map;
}

void			ft_lexer_pop(t_lexer *l)
{
	ASSERT(l->should_pop, "should_pop not set");
	l->should_pop = false;
	l->t.token_map = (--l->states.length == 0) ?
			NULL : &LAST_STATE(l)->token_map;
}

void			ft_lexer_destroy(t_lexer *l, bool destroy)
{
	ft_tokenizer_reset(&l->t, destroy);
	if (destroy)
		ft_vclear(&l->states);
	else
		l->states.length = 0;
	l->token = NULL;
	l->eof = false;
}
