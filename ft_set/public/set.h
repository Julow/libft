/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:34:10 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 18:52:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "ft/libft.h"

typedef struct s_set			t_set;
typedef struct s_set_h			t_set_h;

/*
** ========================================================================== **
** Set
*/

/*
** set object
** 'cmp' is used for comparing keys, take an element and the key to compare
** 'count' store the total element count
** 'flags':
** 		SET_ALLOW_DUP		allow dupplicated keys on insert
** -
** SET(CMP, FLAGS) construct a set object
*/
struct			s_set
{
	void			*data;
	int				(*cmp)(void const *element, void const *key);
	uint32_t		count;
	uint32_t		flags;
};

/*
** set element header
** -
** SET_HEAD() construct an element header
** -
** element's data have to be prefixed with the t_rb_node header
*/
struct			s_set_h
{
	void const *const	data[3];
};

# define SET(CMP, FLAGS)		((t_set){NULL, V(CMP), 0, (FLAGS)})

# define SET_HEAD()				((t_set_h){{NULL, NULL, NULL}})

# define SET_ALLOW_DUP			(1 << 1)

/*
** Search into the set
** 'key' is passed to the cmp function
** Return the matching element or NULL if not found
** If SET_ALLOW_DUP is set, see ft_set_first
*/
void			*ft_set_get(t_set *set, void const *key);
void const		*ft_set_cget(t_set const *set, void const *key);

/*
** Insert an element into the set
** 'key' is only used for comparaison
** Return true on success
** Return false on dupplicated key (if SET_ALLOW_DUP flag is not set)
*/
bool			ft_set_insert(t_set *set, void *element, void const *key);

/*
** Remove an element
** 'element' have to be an element of 'set'
*/
void			ft_set_remove(t_set *set, void *element);

/*
** Return the first/last element in sorted order
** If 'key' is not NULL, return the first/last element that match the key
** Return NULL if the set is empty
*/
void			*ft_set_first(t_set *set, void const *key);
void const		*ft_set_cfirst(t_set const *set, void const *key);

void			*ft_set_last(t_set *set, void const *key);
void const		*ft_set_clast(t_set const *set, void const *key);

/*
** Return the prev/next element in sorted order
** Return NULL after the last element
*/
void			*ft_set_next(void *element);
void const		*ft_set_cnext(void const *element);

void			*ft_set_prev(void *element);
void const		*ft_set_cprev(void const *element);

#endif
