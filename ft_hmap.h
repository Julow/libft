/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 01:35:55 by juloo             #+#    #+#             */
/*   Updated: 2015/06/11 01:37:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include "libft.h"

/*
** ========================================================================== **
** HMap
** Store data using string as index (key)
** The key is hashed to speedup operations
** - Can store pointers and/or data
** - The alloc_size and the hash function must be not modified
** - Each key is unique, dupplicate keys will be overwritten
** - Copied datas are always 0-terminated
** - Datas are not ordered nor continuous
**   (simple iteration and sort are impossible)
*/

typedef struct	s_hmap
{
	int				size;
	int				alloc_size;
	struct s_h		**data;
	int				(*hash)(t_sub key);
}				t_hmap;

void			ft_hmapini(t_hmap *map, int size, int (*h)(t_sub));
void			*ft_hmapget(t_hmap *map, t_sub key);
void			ft_hmapputp(t_hmap *map, t_sub key, void *data);
void			*ft_hmapput(t_hmap *map, t_sub key, void const *d, int l);
void			*ft_hmapput0(t_hmap *map, t_sub key, int size);
void			ft_hmaprem(t_hmap *map, t_sub key, void (*f)(void*));
void			ft_hmapdestroy(t_hmap *map, void (*f)(void*));
int				ft_hmapdatas(t_hmap *map, void **dst);
int				ft_hmapkeys(t_hmap *map, char **dst);

/*
** ========================================================================== **
*/

#endif
