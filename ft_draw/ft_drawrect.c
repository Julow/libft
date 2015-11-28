/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:47:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_draw.h"

void			ft_drawrect(t_image *img, t_rect rect, t_color color)
{
	ft_resrect(&rect, RECT(0, 0, img->width, img->height));
	ft_drawnpt(img, PT(rect.x, rect.y), rect.width, color);
	rect.height += rect.y;
	ft_drawnpt(img, PT(rect.x, rect.height), rect.width, color);
	while (rect.height >= rect.y)
	{
		ft_drawxy(img, rect.x, rect.height, color);
		ft_drawxy(img, rect.x + rect.width, rect.height, color);
		rect.height--;
	}
}
