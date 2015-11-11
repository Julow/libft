/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:55:06 by juloo             #+#    #+#             */
/*   Updated: 2015/11/11 19:39:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sub.h"

t_bool			ft_subequ(t_sub a, t_sub b)
{
	if (a.length == b.length && ft_memcmp(a.str, b.str, a.length) == 0)
		return (true);
	return (false);
}
