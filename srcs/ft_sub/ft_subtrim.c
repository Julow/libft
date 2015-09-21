/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:02:14 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 12:32:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
