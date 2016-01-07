/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 18:23:16 by juloo             #+#    #+#             */
/*   Updated: 2016/01/07 15:13:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BST_H
# define FT_BST_H

# include "ft/libft.h"

typedef struct s_bst_node	t_bst_node;
typedef int					(*t_bst_cmp)(void const*, void const*);
typedef struct s_bst		t_bst;

/*
** ========================================================================== **
** Binary Search Tree
** (implementation: AVL)
*/

struct		s_bst_node
{
	t_bst_node	*left;
	t_bst_node	*right;
	int32_t		height;
};

struct		s_bst
{
	t_bst_node	*root;
	t_bst_cmp	match;
	uint32_t	length;
	uint32_t	node_size;
};

/*
** The 'match' function is used to sort nodes
** The first param is a pointer to the node's data
** The second param is the 'match' param of get/put/del
** The two parameters can be of different type
*/

/*
** Init a t_bst
*/
# define BST(TYPE,CMP)	((t_bst){NULL, (void*)(CMP), 0, sizeof(TYPE)})

/*
** Put a new node
** 'extra_size' bytes are allocated in addition to 'bst->node_size'
** 'match' is only used for comparaison and is not copied
** Return a pointer to the new data
*/
void		*ft_bst_put(t_bst *bst, void const *match, uint32_t extra_size);

/*
** Get the first node that match 'match'
** If 'prev' is not NULL, return the next match
** Return NULL if no match found
*/
void		*ft_bst_get(t_bst const *bst, void *prev, void const *match);

/*
** Call 'f' for each node that match 'match'
** Can replace ft_bst_get if the cmp function is bad
** If 'f' return false, break the iteration and return false
** Return true
** 'f' is of type: bool (*f)(void *node, void const *match, void *env)
*/
bool		ft_bst_getall(t_bst const *bst, void const *match, bool (*f)(),
				void *env);

/*
** Delete the first node that match 'match'
** TODO: ft_bst_del not implemented
*/
void		ft_bst_del(t_bst *bst, void const *match);

/*
** Return the smallest element (left)
*/
void		*ft_bst_min(t_bst const *bst);

/*
** Return the biggest element (right)
*/
void		*ft_bst_max(t_bst const *bst);

/*
** Iter each node in sorted order
** If 'f' return false, break the iteration and return false
** Return true
** 'env' is passed as 2nd argument of 'f'
** f is of type bool (*)(void *node, void *env)
*/
bool		ft_bst_iter(t_bst *bst, bool (*f)(), void *env);

/*
** Destroy a bst
** If 'f' is not NULL, it is applyied to each data
** The 'bst' pointer is not freed
** 'f' is of type void (*)(void *data, void *env);
*/
void		ft_bst_destroy(t_bst *bst, void (*f)(), void *env);

#endif
