/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oset.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:00:26 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/27 15:20:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT__OSET_H
# define FT__OSET_H

# include "ft/libft.h"
# include "ft/set.h"

typedef struct s_oset		t_oset;
typedef struct s_oset_h		t_oset_h;

/*
** ========================================================================== **
** Ordered set
** -
** Subclass of ft::set that keep insertion order
** -
** Except ft_set_insert and ft_set_remove, ft::set functions are compatible
*/

/*
** set				=> set object
** first			=> first (front) element
** last				=> last (back) element
** -
** OSET(CMP, FLAGS)		Construct an ordered set
*/
struct			s_oset
{
	t_set			set;
	void			*first;
	void			*last;
};

/*
** Ordered set element header
** -
** OSET_HEAD()			Construct an ordered set header
** OSET_NEXT(E)			Next element
** OSET_PREV(E)			Previous element
*/
struct			s_oset_h
{
	t_set_h			set_h;
	void			*prev;
	void			*next;
};

# define OSET(CMP, FLAGS)	((t_oset){SET(CMP, FLAGS), NULL, NULL})

# define OSET_HEAD()		((t_oset_h){SET_HEAD(), NULL, NULL})

# define OSET_NEXT(E)		(((t_oset_h const*)(E))->next)
# define OSET_PREV(E)		(((t_oset_h const*)(E))->prev)

/*
** Insert an element into the set
** Same behavior as ft_set_insert
*/
bool			ft_oset_insert(t_oset *set, void *element, void const *key);

/*
** Remove an element from the set
** Same behavior as ft_set_remove
*/
void			ft_oset_remove(t_oset *set, void *element);

#endif
