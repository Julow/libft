/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 19:34:58 by juloo             #+#    #+#             */
/*   Updated: 2016/08/03 17:49:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/lexer.h"
#include "p_lexer.h"

static int		lexer_state_node_cmp(t_lexer_state_node const *n,
					t_sub const *name)
{
	return (SUB_CMP(n->def->name, *name));
}

static void		init_states(t_lexer_def const *def,
					t_lexer_state_node *states, t_set *dst)
{
	uint32_t		i;

	i = 0;
	while (i < def->length)
	{
		states[i] = (t_lexer_state_node){SET_HEAD(), NULL, VECTOR_GET(*def, i)};
		if (!ft_set_insert(dst, &states[i], &states[i].def->name))
		{
			ft_printf("ft::lexer: Redefined state %ts%n", states[i].def->name);
			ASSERT(false);
		}
		i++;
	}
}

static void		destroy_states(t_lexer_state_node *states, uint32_t len)
{
	t_lexer_state_node *const	end = states + len;

	while (states < end)
	{
		if (states->state != NULL)
			destroy_state(states->state);
		states++;
	}
}

t_lexer_state	*ft_lexer_build(t_lexer_def const *def, t_sub main_state)
{
	t_set				state_set;
	t_lexer_state_node	states[def->length];
	t_lexer_state		*state;

	state_set = SET(&lexer_state_node_cmp, 0);
	init_states(def, states, &state_set);
	if ((state = get_state(&state_set, main_state)) == NULL)
		destroy_states(states, def->length);
	return (state);
}
