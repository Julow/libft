/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 01:35:55 by juloo             #+#    #+#             */
/*   Updated: 2015/09/19 12:05:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include "libft.h"

/*
** ========================================================================== **
** Hash
*/

t_uint			ft_djb2(t_sub sub);

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

struct			s_hmap
{
	int				size;
	int const		alloc_size;
	struct s_h		**const data;
	t_uint			(*const hash)(t_sub key);
};

/*
** Alloc a new hmap
*/
t_hmap			*ft_hmapnew(int size, t_uint (*h)(t_sub));

/*
** Retrieve an element
** Return NULL if not found
*/
void			*ft_hmapget(t_hmap const *map, t_sub key);

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
** Do nothing if not found
** Apply 'f' (if not NULL) to the removed element
*/
void			ft_hmaprem(t_hmap *map, t_sub key, void (*f)(void*));

/*
** Destroy the hmap
** The map pointer is also freed (it become invalid)
** 'f' is applied to all element (if not NULL)
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
