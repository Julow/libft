/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 19:52:15 by juloo             #+#    #+#             */
/*   Updated: 2015/10/20 20:08:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bst.h"

typedef struct	s_bst_put
{
	t_bst			*bst;
	void const		*data;
	uint32_t		extra_size;
	void			*dst;
}				t_bst_put;

static t_bst_node	*new_node(t_bst_put *tmp)
{
	t_bst_node	*node;

	node = ft_emalloc(sizeof(t_bst_node) + tmp->bst->node_size + tmp->extra_size);
	node->left = NULL;
	node->right = NULL;
	ft_memcpy(ENDOF(node), tmp->data, tmp->bst->node_size);
	tmp->dst = ENDOF(node);
	return (node);
}

// TODO: store height
static int			bst_node_height(t_bst_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + ft_max(bst_node_height(node->left),
		bst_node_height(node->right)));
}

static t_bst_node	*bst_rot_ll(t_bst_node *node)
{
	t_bst_node *const	tmp = node->left;

	node->left = tmp->right;
	tmp->right = node;
	return (tmp);
}

static t_bst_node	*bst_rot_lr(t_bst_node *node)
{
	t_bst_node *const	tmp = node->left;
	t_bst_node *const	root = tmp->right;

	node->left = root->right;
	tmp->right = root->left;
	root->left = tmp;
	root->right = node;
	return (root);
}

static t_bst_node	*bst_rot_rr(t_bst_node *node)
{
	t_bst_node *const	tmp = node->right;

	node->right = tmp->left;
	tmp->left = node;
	return (tmp);
}

static t_bst_node	*bst_rot_rl(t_bst_node *node)
{
	t_bst_node *const	tmp = node->right;
	t_bst_node *const	root = tmp->left;

	node->right = root->left;
	tmp->left = root->right;
	root->right = tmp;
	root->left = node;
	return (root);
}

static t_bst_node	*bst_rotate_left(t_bst_node *node)
{
	int const	lleft_height = bst_node_height(node->left->left);
	int const	lright_height = bst_node_height(node->left->right);
	int const	balance = lleft_height - lright_height;

	if (balance < 0)
		return (bst_rot_lr(node));
	else
		return (bst_rot_ll(node));
}

static t_bst_node	*bst_rotate_right(t_bst_node *node)
{
	int const	rleft_height = bst_node_height(node->right->left);
	int const	rright_height = bst_node_height(node->right->right);
	int const	balance = rleft_height - rright_height;

	if (balance > 0)
		return (bst_rot_rl(node));
	else
		return (bst_rot_rr(node));
}

static t_bst_node	*bst_balance(t_bst_node *node)
{
	int const	left_height = bst_node_height(node->left);
	int const	right_height = bst_node_height(node->right);
	int const	balance = left_height - right_height;

	if (balance > 1)
		node = bst_rotate_left(node);
	else if (balance < -1)
		node = bst_rotate_right(node);
	return (node);
}

t_bst_node	*bst_put(t_bst_put *tmp, t_bst_node *node)
{
	if (node == NULL)
	{
		tmp->bst->length++;
		return (new_node(tmp));
	}
	if (tmp->bst->cmp(tmp->data, ENDOF(node)) < 0)
		node->left = bst_put(tmp, node->left);
	else
		node->right = bst_put(tmp, node->right);
	return (bst_balance(node));
}

void		*ft_bst_put(t_bst *bst, void const *data, uint32_t extra_size)
{
	t_bst_put	tmp;

	tmp = (t_bst_put){bst, data, extra_size, NULL};
	bst->root = bst_put(&tmp, bst->root);
	return (tmp.dst);
}
