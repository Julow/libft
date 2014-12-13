/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:47:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 14:47:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

void			ft_drawrect(t_image *img, t_pt p1, t_pt p2, t_color color)
{
	t_pt			i;

	ft_resrect(&p1, &p2);
	ft_drawnpt(img, i, p2.x - p1.x, color);
	ft_drawnpt(img, PT(i.x, p2.y), p2.x - p1.x, color);
	i = p1;
	while (i.y < p2.y)
	{
		ft_drawpt(img, i, color);
		ft_drawpt(img, PT(p2.x, i.y), color);
		i.y++;
	}
}
