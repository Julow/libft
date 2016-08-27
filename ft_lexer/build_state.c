/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:13:41 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 19:06:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenmap_builder.h"
#include "p_lexer.h"

#include <stdlib.h>

static bool		push_tokens(t_set *state_set, t_vector const *tokens,
					t_tokenmap_builder *tb)
{
	t_lexer_token_def const	*token_def;
	t_lexer_token			*token;

	token_def = VECTOR_IT(*tokens);
	while (VECTOR_NEXT(*tokens, token_def))
	{
		if ((token = ft_tokenmap_builder_add(tb, token_def->str,
					sizeof(t_lexer_token))) == NULL)
			continue ;
		token->data = token_def->data;
		if (token_def->push == NULL)
			token->push = NULL;
		else if ((token->push = get_state(state_set,
						ft_sub(token_def->push, 0, -1))) == NULL)
			return (false);
		token->pop = token_def->pop;
	}
	return (true);
}

static bool		state_inherit(t_set *state_set, t_vector const *parents,
					t_tokenmap_builder *tb)
{
	t_lexer_state_node const	*state;
	t_sub						name;
	uint32_t					i;

	i = 0;
	while (i < parents->length)
	{
		name = ft_sub(*(char const**)VECTOR_GET(*parents, i), 0, -1);
		if ((state = ft_set_get(state_set, &name)) == NULL)
			return (ft_printf("ft::lexer: Unknown state %ts%n", name), false);
		if (!push_tokens(state_set, &state->def->tokens, tb)
			|| !state_inherit(state_set, &state->def->parents, tb))
			return (false);
		i++;
	}
	return (true);
}

static bool		build_state(t_set *state_set, t_lexer_state_def const *def,
					t_tokenmap_builder *tb)
{
	if (!push_tokens(state_set, &def->tokens, tb)
		|| !state_inherit(state_set, &def->parents, tb))
		return (false);
	return (true);
}

t_lexer_state	*get_state(t_set *state_set, t_sub name)
{
	t_lexer_state_node *const	state = ft_set_get(state_set, &name);
	t_tokenmap_builder			tb;

	if (state == NULL)
		return (ft_printf("ft::lexer: Unknown state %ts%n", name), NULL);
	if (state->state != NULL)
		return (state->state);
	state->state = MALLOC(sizeof(t_lexer_state) + name.length);
	ft_memcpy(ENDOF(state->state), name.str, name.length);
	state->state->name = SUB(ENDOF(state->state), name.length);
	tb = TOKENMAP_BUILDER();
	if (!build_state(state_set, state->def, &tb))
	{
		free(state->state);
		ASSERT(!"TODO: destroy tokenmap_builder");
		state->state = NULL;
	}
	else
		state->state->token_map = ft_tokenmap_builder_done(&tb);
	return (state->state);
}
