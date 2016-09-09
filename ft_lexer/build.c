/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 19:34:58 by juloo             #+#    #+#             */
/*   Updated: 2016/09/09 12:56:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "ft/tokenmap_builder.h"

#include "p_lexer.h"

static t_lexer_state_def const	*get_state_def(t_lexer_def const *def, t_sub n)
{
	t_lexer_state_def const			*state_def;
	t_lexer_def const				**lib;

	state_def = VECTOR_IT(def->def);
	while (VECTOR_NEXT(def->def, state_def))
	{
		if (SUB_EQU(n, state_def->name))
			return (state_def);
	}
	lib = VECTOR_IT(def->libs);
	while (VECTOR_NEXT(def->libs, lib))
	{
		if ((state_def = get_state_def(*lib, n)) != NULL)
			return (state_def);
	}
	ASSERT(!"Unknown state");
	return (NULL);
}

static void		push_tokens(t_lexer_state_def const *state_def,
					t_tokenmap_builder *tb)
{
	t_lexer_token_def const	*token_def;

	token_def = VECTOR_IT(state_def->tokens);
	while (VECTOR_NEXT(state_def->tokens, token_def))
	{
		ft_tokenmap_builder_add(tb, token_def->str, token_def->data);
	}
}

static void		state_inherit(t_lexer_def const *def, t_sub name,
					t_tokenmap_builder *tb)
{
	t_lexer_state_def const *const	state_def = get_state_def(def, name);
	t_sub							parent_name;
	uint32_t						i;

	if (state_def == NULL)
		return ;
	push_tokens(state_def, tb);
	i = 0;
	while (i < state_def->parents.length)
	{
		parent_name = ft_sub(VGETC(char const*, state_def->parents, i), 0, -1);
		state_inherit(def, parent_name, tb);
		i++;
	}
}

t_tokenmap		*lexer_build_state(t_lexer_def const *def)
{
	t_tokenmap_builder			tb;

	tb = TOKENMAP_BUILDER();
	state_inherit(def, def->main_state, &tb);
	return (ft_tokenmap_builder_done(&tb));
}
