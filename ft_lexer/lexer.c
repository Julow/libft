/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:50:51 by juloo             #+#    #+#             */
/*   Updated: 2016/11/19 19:40:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

void			ft_lexer_push(t_tokenizer *t, t_lexer_frame *save,
					t_lexer_def *def)
{
	*save = t->token_map;
	if (def->tokenmap == NULL)
		def->tokenmap = lexer_build_state(def);
	t->token_map = def->tokenmap;
}

void			ft_lexer_pop(t_tokenizer *t, t_lexer_frame const *prev)
{
	t->token_map = *prev;
}
