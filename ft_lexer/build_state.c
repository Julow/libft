/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:13:41 by juloo             #+#    #+#             */
/*   Updated: 2016/08/03 16:19:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lexer.h"

static bool		push_tokens(t_set *state_set, t_vector const *tokens,
					t_lexer_state *dst)
{
	t_lexer_token_def const	*token_def;
	t_lexer_token			*token;

	token_def = VECTOR_IT(*tokens);
	while (VECTOR_NEXT(*tokens, token_def))
	{
		if ((token = ft_tokenmap_add(&dst->token_map, token_def->str,
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
					t_lexer_state *dst)
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
		if (!build_state(state_set, state->def, dst))
			return (false);
		i++;
	}
	return (true);
}

bool			build_state(t_set *state_set, t_lexer_state_def const *def,
					t_lexer_state *dst)
{
	if (!push_tokens(state_set, &def->tokens, dst))
		return (false);
	if (!state_inherit(state_set, &def->parents, dst))
		return (false);
	return (true);
}

t_lexer_state	*get_state(t_set *state_set, t_sub name)
{
	t_lexer_state_node *const	state = ft_set_get(state_set, &name);

	if (state == NULL)
		return (ft_printf("ft::lexer: Unknown state %ts%n", name), NULL);
	if (state->state != NULL)
		return (state->state);
	state->state = MALLOC(sizeof(t_lexer_state) + name.length);
	*state->state = (t_lexer_state){
		SUB(ENDOF(state->state), name.length),
		TOKEN_MAP()
	};
	ft_memcpy(ENDOF(state->state), name.str, name.length);
	if (!build_state(state_set, state->def, state->state))
	{
		destroy_state(state->state);
		state->state = NULL;
	}
	return (state->state);
}
