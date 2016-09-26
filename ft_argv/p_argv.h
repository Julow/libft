/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_argv.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:56:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/25 18:40:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ARGV_H
# define P_ARGV_H

# include "ft/argv.h"

typedef struct s_argv_state		t_argv_state;

/*
** ========================================================================== **
*/

struct			s_argv_state
{
	t_vec2u			i;
	uint32_t		flags;
};

# define ARGV_STATE(ARGV)		((t_argv_state){(ARGV)->i, (ARGV)->flags})

# define ARGV_RESTORE(A, S)		((A)->i = (S).i, (A)->flags = (S).flags)

extern t_argv_opt_err	(*const g_argv_opt_value[])(t_sub, void*);
extern t_argv_opt_err	(*const g_argv_opt[])(t_argv *args,
							t_argv_opt const *opt, void *dst);

#endif
