/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:34:10 by juloo             #+#    #+#             */
/*   Updated: 2017/03/01 13:39:21 by jaguillo         ###   ########.fr       */
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
** 'root' is the root node
** 'cmp' is used for comparing keys, take an element and the key to compare
** 'update' is called every times a node's child change or with ft_set_update
** 'count' store the total element count
** -
** SET(CMP, UPDATE) construct a set object
*/
struct			s_set
{
	void			*root;
	int				(*cmp)(void const *element, void const *key);
	void			(*update)(void *element);
	uint32_t		count;
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
	void const *const	data;
	void *const			left;
	void *const			right;
};

# define SET(CMP, UPDATE)		((t_set){NULL, V(CMP), V(UPDATE), 0})

# define SET_HEAD()				((t_set_h){NULL, NULL, NULL})

/*
** Search into the set
** 'key' is passed to the cmp function
** Return the matching element or NULL if not found
*/
void			*ft_set_get(t_set *set, void const *key);
void const		*ft_set_cget(t_set const *set, void const *key);

/*
** Insert an element into the set
** 'key' is only used for comparaison
*/
void			ft_set_insert(t_set *set, void *element, void const *key);

/*
** Insert an element before 'before'
** The following condition must be true:
** 	prev(before) <= node <= before
** If 'before' is NULL, insert at the end
*/
void			ft_set_insert_before(t_set *set, void *element, void *before);

/*
** Remove an element
** 'element' have to be an element of 'set'
*/
void			ft_set_remove(t_set *set, void *element);

/*
** Update the tree starting at 'element' to the top
*/
void			ft_set_update(t_set *set, void *element);

/*
** Returns the first element (in sorted order) where element >= key
** If 'key' is NULL, returns the first element in the set
** Returns NULL if there is no match
*/
void			*ft_set_begin(t_set *set, void const *key);
void const		*ft_set_cbegin(t_set const *set, void const *key);

/*
** Returns the element
** 	after the last element (in sorted order) where element >= key
** If 'key' is NULL, returns NULL
*/
void			*ft_set_end(t_set *set, void const *key);
void const		*ft_set_cend(t_set const *set, void const *key);

/*
** Return the prev/next element in sorted order
** Return NULL after the last element
*/
void			*ft_set_next(void *element);
void const		*ft_set_cnext(void const *element);

void			*ft_set_prev(void *element);
void const		*ft_set_cprev(void const *element);

/*
** Clear the set (remove all elements)
** If not NULL, call 'f' on each elements (in sorted order)
*/
void			ft_set_clear(t_set *set, void (*f)(void *element));

#endif
