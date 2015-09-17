/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 23:28:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:54:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

t_pt			ft_nearest(t_pt pos, t_pt p1, t_pt p2)
{
	const t_pt		t1 = PT(p1.x - pos.x, p1.y - pos.y);
	const t_pt		t2 = PT(p2.x - pos.x, p2.y - pos.y);

	if (((t1.x * t1.x) + (t1.y * t1.y)) > ((t2.x * t2.x) + (t2.y * t2.y)))
		return (p2);
	return (p1);
}