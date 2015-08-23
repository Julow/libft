/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 15:54:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"

void			ft_tabrev(t_tab *tab)
{
	int				i;
	const int		middle = tab->length / 2;

	i = -1;
	while (++i < middle)
		ft_tabswap(tab, i, tab->length - i - 1);
}
