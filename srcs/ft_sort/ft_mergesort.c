/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 14:57:16 by juloo             #+#    #+#             */
/*   Updated: 2015/04/27 18:03:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		merge(void **tab, int len1, int len2, int (*cmp)())
{
	int				i1;
	int				i2;
	int				tmp_i;
	void			*tmp[len2 += len1];

	i1 = 0;
	i2 = len1;
	tmp_i = -1;
	while (++tmp_i < len2)
		if (i1 >= len1)
			tmp[tmp_i] = tab[i2++];
		else if (i2 >= len2)
			tmp[tmp_i] = tab[i1++];
		else if (cmp(tab[i1], tab[i2]) > 0)
			tmp[tmp_i] = tab[i2++];
		else
			tmp[tmp_i] = tab[i1++];
	while (--tmp_i >= 0)
		tab[tmp_i] = tmp[tmp_i];
}

void			ft_mergesort(void **tab, int length, int (*cmp)())
{
	int				len1;
	int				len2;
	void			*tmp;

	if (length > 2)
	{
		len1 = length / 2 + length % 2;
		len2 = length / 2;
		ft_mergesort(tab, len1, cmp);
		ft_mergesort(tab + len1, len2, cmp);
		merge(tab, len1, len2, cmp);
	}
	else if (length == 2 && cmp(tab[0], tab[1]) > 0)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}
