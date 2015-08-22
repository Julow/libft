/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 01:35:55 by juloo             #+#    #+#             */
/*   Updated: 2015/08/22 23:03:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include "libft.h"

/*
** ========================================================================== **
** HashMap
** Store data using key
** Keys are hashed to speedup get/put operations
** - Can store pointers and/or data
** - The alloc_size and the hash function cannot be modified
** - Each key are unique, dupplicate keys will be overwritten
** - Copied datas are always 0-terminated
** - Datas are not ordered nor continuous
**   (simple iteration and sort are not possible)
*/

typedef struct	s_hmap
{
	int				size;
	int const		alloc_size;
	struct s_h		**data;
	int				(const *hash)(t_sub key);
}				t_hmap;

/*
** Init a hmap
** (make an alloc)
*/
void			ft_hmapini(t_hmap *map, int size, int (*h)(t_sub));

/*
** Retrieve an element
** Return NULL if not found
*/
void			*ft_hmapget(t_hmap *map, t_sub key);

/*
** Put 'data' into the hmap
** The content of 'data' is not copied and won't be freed if it is overrided
*/
void			ft_hmapputp(t_hmap *map, t_sub key, void *data);

/*
** Put the content of 'data' into the hmap
** an extra NUL byte is added
** if 'data' is NULL, the data is bzero
** Return a pointer to the data
*/
void			*ft_hmapput(t_hmap *map, t_sub key, void const *data, int size);

/*
** Remove an element of the hmap
*/
void			ft_hmaprem(t_hmap *map, t_sub key, void (*f)(void*));

/*
** Destroy the hmap
** The hmap is unusable
*/
void			ft_hmapdestroy(t_hmap *map, void (*f)(void*));

/*
** Fill 'dst' with all datas or keys
** Stop at 'max' (if 'max' >= 0)
** Return the total of copied elements
*/
int				ft_hmapdatas(t_hmap *map, void **dst, int max);
int				ft_hmapkeys(t_hmap *map, char **dst, int max);

/*
** ========================================================================== **
*/

#endif
