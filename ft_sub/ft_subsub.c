/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:04:51 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"

/*
** ft_subsub
** ----
** See ft_sub
*/

t_sub			ft_subsub(t_sub sub, int from, int to)
{
	if (from < 0)
		from += sub.length + 1;
	if (to < 0)
		to += sub.length + 1;
	return ((t_sub){sub.str + from, to - from});
}
