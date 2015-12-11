/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/11 11:43:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETKEY_INTERNAL_H
# define GETKEY_INTERNAL_H

# include "ft/getkey.h"

typedef struct s_seq_end	t_seq_end;

struct		s_seq_end
{
	int			end;
	int			c;
	uint32_t	mods;
};

char			next_char(int fd);

t_key			get_esc_seq(int fd);

#endif
