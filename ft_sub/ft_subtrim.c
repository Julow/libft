/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:02:14 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"

/*
** ft_subtrim
** ----
** See ft_subtriml
** See ft_subtrimr
*/

int				ft_subtrim(t_sub *sub, t_is mask)
{
	return (ft_subtriml(sub, mask) + ft_subtrimr(sub, mask));
}
