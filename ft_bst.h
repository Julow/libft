/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 18:23:16 by juloo             #+#    #+#             */
/*   Updated: 2015/10/20 22:06:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BST_H
# define FT_BST_H

typedef struct s_bst_node	t_bst_node;
typedef struct s_bst		t_bst;

# include "libft.h"

/*
** ========================================================================== **
** Binary Search Tree
** (implementation: AVL)
*/

struct s_bst_node
{
	t_bst_node	*left;
	t_bst_node	*right;
	int32_t		height;
};

struct s_bst
{
	t_bst_node	*root;
	int			(*cmp)(void const*, void const*);
	uint32_t	length;
	uint32_t	node_size;
};

# define BST(TYPE,CMP)	((t_bst){NULL, (void*)(CMP), 0, sizeof(TYPE)})

/*
** Put a new node
** 'extra_size' bytes are allocated in addition to 'bst->node_size'
** Only 'bst->node_size' bytes are copied from 'data'
** Return a pointer to the new data
*/
void		*ft_bst_put(t_bst *bst, void const *data, uint32_t extra_size);

/*
** Get the first node that match 'match'
** Return NULL if no match found
*/
void		*ft_bst_get(t_bst *bst, void const *match);

/*
** Delete the first node that match 'match'
** TODO: ft_bst_del not implemented
*/
void		ft_bst_del(t_bst *bst, void const *match);

/*
** Return the smallest element (left)
*/
void		*ft_bst_min(t_bst *bst);

/*
** Return the biggest element (right)
*/
void		*ft_bst_max(t_bst *bst);

/*
** Iter each node in sorted order
** If 'f' return false, break the iteration and return false
** Return true
** 'env' is passed as 2nd argument of 'f'
*/
t_bool		ft_bst_iter(t_bst *bst, t_bool (*f)(void*, void*), void *env);

#endif
