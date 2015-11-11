/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:03:15 by juloo             #+#    #+#             */
/*   Updated: 2015/11/11 19:39:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sub.h"

/*
** ft_subnext
** ----
** Iter into a string using the rules of ft_subextract
** ----
** Note: Be sure that 'sub->length' is 0 before the iteration
** ----
** Return 'false' if the end of the string is reach
** 'true' otherwise
*/

t_bool			ft_subnext(t_sub *sub, t_is mask)
{
	int				i;

	sub->str += sub->length;
	i = 0;
	while (IS(sub->str[i], mask) && sub->str[i] != '\0')
		i++;
	sub->str += i;
	if (sub->str[0] == '\0')
	{
		sub->length = 0;
		return (false);
	}
	i = 0;
	while (!IS(sub->str[i], mask) && sub->str[i] != '\0')
		i++;
	sub->length = i;
	return (true);
}
