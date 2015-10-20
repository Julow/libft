/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 15:07:14 by juloo             #+#    #+#             */
/*   Updated: 2015/10/20 21:07:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bst.h"
#include "ft_out.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** ========================================================================== **
** bst print
*/

typedef void				(*t_bst_print_f)(t_out *out, void const*);

static void		bst_print(t_out *out, t_bst_node const *node, int indent,
					t_bool right, t_bst_print_f print)
{
	int				i;

	if (node->left != NULL)
		bst_print(out, node->left, indent + 1, false, print);
	i = -1;
	while (++i < indent)
		ft_writestr(out, "   ");
	ft_writestr(out, right ? "`- " : ",- ");
	print(out, ENDOF(node));
	ft_writechar(out, '\n');
	if (node->right != NULL)
		bst_print(out, node->right, indent + 1, true, print);
}

void			ft_bst_print(t_out *out, t_bst const *bst, t_bst_print_f print)
{
	if (bst->root == NULL)
		return ;
	if (bst->root->left != NULL)
		bst_print(out, bst->root->left, 1, false, print);
	ft_writestr(out, "- ");
	print(out, ENDOF(bst->root));
	ft_writechar(out, '\n');
	if (bst->root->right != NULL)
		bst_print(out, bst->root->right, 1, true, print);
	// ft_flush(out);
	NL;
}

/*
** ========================================================================== **
*/

static int			bst_node_height(t_bst_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + ft_max(bst_node_height(node->left),
		bst_node_height(node->right)));
}

void			test_height(t_bst_node *node)
{
	if (node == NULL)
		return ;
	if (node->height != bst_node_height(node))
	{
		printf("ERROR: Bad height: %d vs %d (%d)\n", node->height,
			bst_node_height(node), *(int*)ENDOF(node));
		return ;
	}
	test_height(node->left);
	test_height(node->right);
}

int				int_cmp(int const *a, int const *b)
{
	return (*a - *b);
}

void			int_print(t_out *out, int const *a)
{
	ft_writeint(out, *a);
}

t_bool			int_issort(int const *a, int const *prev)
{
	if (a <= prev)
		return (true);
	return (false);
}

void			put_int(t_bst *bst, int i)
{
	ft_bst_put(bst, &i, 0);
}

int				main(void)
{
	t_bst			bst;
	int				tmp;

	srand(time(NULL));
	bst = BST(int, &int_cmp);
	// ft_bst_print(FTOUT, &bst, (t_bst_print_f)&int_print);
	for (int i = 0; i < 100; i++)
		put_int(&bst, rand());
	// ft_bst_print(FTOUT, &bst, (t_bst_print_f)&int_print);
	for (int i = 100; i > 0; i--)
		ft_bst_put(&bst, &i, 0);
	for (int i = 0; i < 500; i++)
		put_int(&bst, rand());
	ft_bst_print(FTOUT, &bst, (t_bst_print_f)&int_print);
	tmp = *(int*)ft_bst_min(&bst);
	if (!ft_bst_iter(&bst, &int_issort, &tmp))
		printf("ERROR: not sort\n");
	test_height(bst.root);
	printf("Height: %d\n", bst.root->height);
	return (0);
}
