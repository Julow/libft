/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:47:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:54:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

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
