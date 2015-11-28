/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:03:25 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"

/*
** ft_subcount
** ----
** Return the count of blocks of characters that match the mask
** ----
** See ft_subextract
*/

int				ft_subcount(t_sub sub, t_is mask)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (!IS(sub.str[i], mask) && i < sub.length)
		i++;
	while (i < sub.length)
	{
		while (IS(sub.str[i], mask))
			i++;
		count++;
		while (!IS(sub.str[i], mask) && i < sub.length)
			i++;
	}
	return (count);
}
