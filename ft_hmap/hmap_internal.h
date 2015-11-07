/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 14:56:07 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:59:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HMAP_INTERNAL_H
# define HMAP_INTERNAL_H

# include "libft.h"
# include "ft_hmap.h"

typedef struct	s_h
{
	t_uint			hash;
	int				key_len;
	void			*data;
	struct s_h		*next;
}				t_h;

# define HMAP_H_KEY(h)	((char*)(((void*)(h)) + sizeof(t_h)))

void			hmap_puth(t_hmap *map, t_h *h);

#endif
