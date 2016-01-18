/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 14:56:07 by juloo             #+#    #+#             */
/*   Updated: 2016/01/18 18:19:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HMAP_INTERNAL_H
# define HMAP_INTERNAL_H

# include "ft/ft_hmap.h"
# include "ft/libft.h"

typedef struct	s_h
{
	uint32_t		hash;
	uint32_t		key_len;
	void			*data;
	struct s_h		*next;
}				t_h;

# define HMAP_H_KEY(h)	((char*)(((void*)(h)) + sizeof(t_h)))

void			hmap_puth(t_hmap *map, t_h *h);

#endif
