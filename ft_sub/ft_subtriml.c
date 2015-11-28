/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtriml.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:02:28 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"

/*
** ft_subtriml
** ----
** Reduce from the left (start) while mask match
** ----
** Return the total of reduced chars
** ----
*/

int				ft_subtriml(t_sub *sub, t_is mask)
{
	int				i;

	i = 0;
	while (i < sub->length && IS(sub->str[i], mask))
		i++;
	sub->str += i;
	sub->length -= i;
	return (i);
}
