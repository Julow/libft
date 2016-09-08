/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:50:51 by juloo             #+#    #+#             */
/*   Updated: 2016/09/08 18:44:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

void			ft_lexer_push(t_lexer *l, t_lexer_frame *save, t_lexer_def *def)
{
	*save = l->state;
	if (def->state == NULL)
		def->state = lexer_build_state(def);
	l->state = def->state;
	l->t.token_map = l->state->token_map;
}

void			ft_lexer_pop(t_lexer *l, t_lexer_frame const *prev)
{
	l->state = *prev;
	l->t.token_map = (l->state == NULL) ? NULL : l->state->token_map;
}

void			ft_lexer_destroy(t_lexer *l)
{
	ft_tokenizer_reset(&l->t, true);
}

// TODO: directly use tokenizer ? throw out this proxy shit
bool			ft_lexer_next(t_lexer *l)
{
	t_lexer_token const	*token;

	if (!ft_tokenize(&l->t))
	{
		l->token = NULL;
		l->eof = l->t.eof;
		return (false);
	}
	l->token = ((token = l->t.token) == NULL) ? NULL : token->data;
	return (true);
}

bool			ft_lexer_ahead(t_lexer *l, t_sub *s, void const **data)
{
	t_lexer_token const	*token;

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
