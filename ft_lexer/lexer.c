/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:50:51 by juloo             #+#    #+#             */
/*   Updated: 2016/08/03 18:09:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

void			ft_lexer_push(t_lexer *l, t_lexer_state const *state)
{
	ft_vpush(&l->states, &state, 1);
	l->t.token_map = &state->token_map;
}

void			ft_lexer_pop(t_lexer *l)
{
	if (l->states.length == 0)
		HARD_ASSERT(!"Pop on empty lexer");
	if (--l->states.length == 0)
		l->t.token_map = NULL;
	else
		l->t.token_map = &LAST_STATE(*l)->token_map;
}

void			ft_lexer_destroy(t_lexer *l, bool destroy)
{
	ft_tokenizer_reset(&l->t, destroy);
	l->states.length = 0;
	l->token = NULL;
	if (destroy)
		ft_vclear(&l->states);
}
