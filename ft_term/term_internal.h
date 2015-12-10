/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:12:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 18:07:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_INTERNAL_H
# define TERM_INTERNAL_H

# include "ft/term.h"

/*
** ========================================================================== **
** term
*/

void		term_out_flush(t_term *term);

/*
** ========================================================================== **
** getkey
*/

typedef struct s_seq_end	t_seq_end;

struct		s_seq_end
{
	int			end;
	int			c;
	uint32_t	mods;
};

#endif
