/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:48:42 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 19:16:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

#include <stdlib.h>

// static void		states_to_destroy(t_set *set, t_lexer_state *state);

// static int		state_destroy_cmp(t_lexer_state_destroy const *d,
// 					t_lexer_state const *const *s)
// {
// 	return (((uintptr_t)d->state) - ((uintptr_t)s));
// }

// static bool		token_iter(t_token_map_t *t, t_set *set)
// {
// 	t_lexer_token const *const	l_token = ENDOF(t);

// 	if (l_token->push != NULL)
// 		states_to_destroy(set, l_token->push);
// 	return (true);
// }

// static void		states_to_destroy(t_set *set, t_lexer_state *state)
// {
// 	t_lexer_state_destroy	*d;

// 	if (ft_set_cget(set, &state) != NULL)
// 		return ;
// 	d = NEW(t_lexer_state_destroy);
// 	*d = (t_lexer_state_destroy){SET_HEAD(), state};
// 	ft_set_insert(set, d, &state);
// 	ft_bst_iter(&state->token_map.tokens, &token_iter, set);
// }

// void			destroy_state(t_lexer_state *state)
// {
// 	ft_tokenmap_destroy(&state->token_map, NULL);
// 	free(state);
// }

// void			ft_lexer_destroy_state(t_lexer_state *state)
// {
// 	t_set					destroy_set;
// 	t_lexer_state_destroy	*d;
// 	t_lexer_state_destroy	*tmp;

// 	destroy_set = SET(&state_destroy_cmp, 0);
// 	states_to_destroy(&destroy_set, state);
// 	d = ft_set_first(&destroy_set, NULL);
// 	while (d != NULL)
// 	{
// 		tmp = ft_set_next(d);
// 		destroy_state(d->state);
// 		free(d);
// 		d = tmp;
// 	}
// }

void			destroy_state(t_lexer_state *state)
{
	ASSERT(!"TODO: ft_lexer_destroy_state");
	(void)state;
}

void			ft_lexer_destroy_state(t_lexer_state *state)
{
	ASSERT(!"TODO: ft_lexer_destroy_state");
	(void)state;
}
