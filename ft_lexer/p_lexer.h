/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 20:36:57 by juloo             #+#    #+#             */
/*   Updated: 2016/08/08 20:03:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_LEXER_BUILD_H
# define P_LEXER_BUILD_H

# include "ft/lexer.h"
# include "ft/set.h"

typedef struct s_lexer_state_node		t_lexer_state_node;
typedef struct s_lexer_state_destroy	t_lexer_state_destroy;

/*
** ========================================================================== **
** Lexer
*/

# define VLAST(T, V)	(VGET(T, V, (V).length - 1))

# define LAST_STATE(L)	(VLAST(t_lexer_state const*, (L)->states))

/*
** ========================================================================== **
** Build
*/

struct			s_lexer_state_node
{
	t_set_h					set_h;
	t_lexer_state			*state;
	t_lexer_state_def const	*def;
};

t_lexer_state	*get_state(t_set *state_set, t_sub name);

/*
** ========================================================================== **
** State destroy
*/

struct			s_lexer_state_destroy
{
	t_set_h			set_h;
	t_lexer_state	*state;
};

void			destroy_state(t_lexer_state *state);

#endif
