/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 01:26:11 by juloo             #+#    #+#             */
/*   Updated: 2015/05/04 02:02:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test_hash(char const *str, int len)
{
	if (len <= 0)
		return (0);
	return (str[0]);
}

static void		test_rem(void *str)
{
	ft_printf("Removing: %s\n", str);
}

int				main(void)
{
	t_hmap			hmap;

	ft_hmapini(&hmap, 5, &test_hash);
	ft_printf("LOL: %s\n", ft_hmapget(&hmap, "LOL"));
	ft_printf("\\1: %s\n", ft_hmapget(&hmap, "\1"));
	ft_hmapget(&hmap, "");
	ft_hmapget(&hmap, "\1");
	ft_printf("len: %d\n", hmap.size);
	ft_hmapput(&hmap, "\1", "test\\1", 6);
	ft_printf("len: %d\n", hmap.size);
	ft_hmapput(&hmap, "\1", "test\\1 (2)", 10);
	ft_printf("len: %d\n", hmap.size);
	ft_hmapput(&hmap, "LOL", "testLOL", 7);
	ft_hmapput(&hmap, "a", "testa", 5);
	ft_hmapput(&hmap, "1", "test1", 5);
	ft_hmapput(&hmap, "\xFF", "test\\xFF", 8);
	ft_hmapput(&hmap, "", "test''", 6);
	ft_printf("len: %d\n", hmap.size);
	ft_hmapget(&hmap, "");
	ft_hmapget(&hmap, "\1");
	ft_printf("LOL: %s\n", ft_hmapget(&hmap, "LOL"));
	ft_printf("\\1: %s\n", ft_hmapget(&hmap, "\1"));
	ft_hmaprem(&hmap, "\1", &test_rem);
	ft_printf("len: %d\n", hmap.size);
	ft_hmaprem(&hmap, "\1", &test_rem);
	ft_printf("LOL: %s\n", ft_hmapget(&hmap, "LOL"));
	ft_printf("\\1: %s\n", ft_hmapget(&hmap, "\1"));
	ft_hmaprem(&hmap, "LOL", &test_rem);
	ft_printf("len: %d\n", hmap.size);
	ft_hmaprem(&hmap, "LOL", NULL);
	ft_printf("LOL: %s\n", ft_hmapget(&hmap, "LOL"));
	ft_printf("\\1: %s\n", ft_hmapget(&hmap, "\1"));
	ft_printf("len: %d\n", hmap.size);
	ft_hmapdestroy(&hmap, &test_rem);
	return (0);
}
