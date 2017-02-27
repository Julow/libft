/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:45:02 by juloo             #+#    #+#             */
/*   Updated: 2017/02/27 23:03:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/libft.h"
#include "ft/set.h"

/*
** ========================================================================== **
*/

typedef struct s_test			t_test;

struct			s_test
{
	t_set_h			set_head;
	int32_t			key;
};

#define TEST(KEY)	((t_test){SET_HEAD(), (KEY)})

int				test_cmp(t_test const *test, int32_t const *key)
{
	return (test->key - *key);
}

/*
** ========================================================================== **
*/

uint32_t		test_order_count(t_set const *set)
{
	t_test const	*test;
	t_test const	*next;
	uint32_t		count;

	if ((test = ft_set_cbegin(set, NULL)) == NULL)
		return (0);
	count = 1;
	while ((next = ft_set_cnext(test)) != NULL)
	{
		ASSERT(next->key >= test->key, "ORDER ERROR");
		test = next;
		count++;
	}
	return (count);
}

void			test_get(t_set const *set)
{
	t_test const	*test;

	test = ft_set_cbegin(set, NULL);
	while (test != NULL)
	{
		ASSERT(ft_set_cget(set, &test->key) != NULL);
		test = ft_set_cnext(test);
	}
}

uint32_t		test_begin(t_set const *set)
{
	t_test const	*test;
	t_test const	*begin;
	t_test const	*end;
	t_test const	*tmp;
	uint32_t		count;
	uint32_t		max;

	max = 0;
	test = ft_set_cbegin(set, NULL);
	while (test != NULL)
	{
		count = 0;
		begin = ft_set_cbegin(set, &test->key);
		ASSERT(begin != NULL, "BEGIN FAIL ERROR");
		tmp = ft_set_cprev(begin);
		ASSERT(tmp == NULL || tmp->key != begin->key, "BAD BEGIN ERROR");
		end = ft_set_cend(set, &test->key);
		ASSERT(end == NULL || end->key != begin->key, "BAD END ERROR");
		while (begin != end)
		{
			ASSERT(begin->key == test->key, "BEGIN/END RANGE ERROR");
			count++;
			begin = ft_set_cnext(begin);
		}
		ASSERT(count > 0, "BEGIN/END ERROR");
		max = MAX(max, count);
		test = ft_set_cnext(test);
	}
	return (max);
}

/*
** ========================================================================== **
*/

void			print_tree(t_test const *node)
{
	if (node == NULL)
		return ;
	print_tree(node->set_head.left);
	ft_printf("%d%n", node->key);
	print_tree(node->set_head.right);
}

void			print_iter(t_set const *set)
{
	t_test const	*node;

	node = ft_set_cbegin(set, NULL);
	while (node != NULL)
	{
		ft_printf("%d%n", node->key);
		node = ft_set_cnext(node);
	}
}

uint32_t		max_height(t_set_h const *node)
{
	uint32_t const	left = node->left ? max_height(node->left) : 0;
	uint32_t const	right = node->right ? max_height(node->right) : 0;

	return (MAX(left, right) + 1);
}

uint32_t		min_height(t_set_h const *node)
{
	uint32_t const	left = node->left ? max_height(node->left) : 0;
	uint32_t const	right = node->right ? max_height(node->right) : 0;

	return (MIN(left, right) + 1);
}

uint32_t		count_occur(t_set const *set, uint32_t key)
{
	uint32_t			count;
	t_test const		*begin;
	t_test const *const	end = ft_set_cend(set, &key);

	count = 0;
	begin = ft_set_cbegin(set, &key);
	while (begin != end)
	{
		count++;
		begin = ft_set_cnext(begin);
	}
	return (count);
}

#define TEST_SIZE		1000000

int				main(void)
{
	t_set			set;
	t_test *const	nodes = NEW_N(t_test, TEST_SIZE);

	set = SET(&test_cmp, 0);

	{
		uint32_t		i;

		i = 0;
		while (i < TEST_SIZE)
		{
			nodes[i] = TEST(ft_rand(-TEST_SIZE*2, TEST_SIZE*2));
			ft_set_insert(&set, &nodes[i], &nodes[i].key);
			i++;
		}
	}

	ASSERT(test_order_count(&set) == TEST_SIZE, "COUNT ERROR");
	test_get(&set);
	ft_printf("MAX DUPP: %u%n", test_begin(&set));

	t_vec2u			range;

	range.x = ft_rand(0, TEST_SIZE / 2);
	range.y = ft_rand(TEST_SIZE / 2, TEST_SIZE);

	{
		uint32_t		i;
		uint32_t		occur;

		i = range.x;
		while (i < range.y)
		{
			occur = count_occur(&set, nodes[i].key);
			ft_set_remove(&set, &nodes[i]);
			ASSERT(occur == count_occur(&set, nodes[i].key) + 1, "REMOVE ERROR");
			i++;
		}
	}

	test_order_count(&set);
	test_get(&set);
	test_begin(&set);
	ASSERT(max_height(set.root) <= min_height(set.root) * 2, "BALANCE ERROR");

	{
		uint32_t		i;
		uint32_t		occur;

		i = range.y;
		while (--i >= range.x)
		{
			occur = count_occur(&set, nodes[i].key);
			ft_set_insert(&set, &nodes[i], &nodes[i].key);
			ASSERT(occur == count_occur(&set, nodes[i].key) - 1, "INSERT ERROR");
		}
	}

	test_order_count(&set);
	test_get(&set);
	test_begin(&set);
	ASSERT(max_height(set.root) <= min_height(set.root) * 2, "BALANCE ERROR");

	{
		uint32_t		i;

		i = 0;
		while (i < 100)
		{
			ft_set_remove(&set, &nodes[0]);
			nodes[0].key = ft_rand(-TEST_SIZE*2, TEST_SIZE*2);
			ft_set_insert(&set, &nodes[0], &nodes[0].key);
			i++;
		}
	}

	test_order_count(&set);
	test_get(&set);
	test_begin(&set);
	ASSERT(max_height(set.root) <= min_height(set.root) * 2, "BALANCE ERROR");

	// print_tree(set.root);
	// print_iter(&set);

	return (0);
}
