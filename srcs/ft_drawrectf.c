/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrectf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:48:00 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 14:48:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

void			ft_drawrectf(t_image *img, t_pt p1, t_pt p2, t_color color)
{
	ft_resrect(&p1, &p2);
	while (p1.y < p2.y)
	{
		ft_drawnpt(img, p1, p2.x - p1.x, color);
		p1.y++;
	}
}
