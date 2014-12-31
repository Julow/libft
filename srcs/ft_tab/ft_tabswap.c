/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:30 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:05:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabswap(t_tab *tab, int i1, int i2)
{
	if (i1 >= tab->length || i2 >= tab->length)
		if (!ft_tabext(tab, MAX(i1, i2) - tab->length + 1))
			return ;
	ft_memswap(TI(tab, i1), TI(tab, i2), tab->size);
}
