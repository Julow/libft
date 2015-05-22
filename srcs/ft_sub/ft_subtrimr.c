/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtrimr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:02:39 by juloo             #+#    #+#             */
/*   Updated: 2015/05/23 01:13:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_subtrimr
** ----
** Reduce from the right (end) while mask match
** ----
** Return the total of reduced chars
** ----
*/
int				ft_subtrimr(t_sub *sub, t_is mask)
{
	int				i;
	int				tmp;

	i = sub->length - 1;
	while (i >= 0 && IS(sub->str[i], mask))
		i--;
	i++;
	tmp = sub->length - i;
	sub->length = i;
	return (tmp);
}
