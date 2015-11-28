/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imageclrc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 15:10:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_draw.h"

void			ft_imageclrc(t_image *img, t_color color)
{
	int				end;

	end = img->width * img->height * img->opp;
	if (color.b.b == color.b.g && color.b.g == color.b.r)
	{
		ft_memset(img->data, color.i, end);
		return ;
	}
	while ((end -= img->opp) >= 0)
		IMAGEPOS(img, end) = color;
}
