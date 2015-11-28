/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawxy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:40:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:44:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_draw.h"

inline void		ft_drawxy(t_image *img, int x, int y, t_color color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	if (ALPHA(color))
		ft_resalpha(&color, IMAGEPT(img, x, y));
	IMAGEPT(img, x, y) = color;
}
