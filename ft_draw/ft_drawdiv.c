/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawdiv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 15:18:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:54:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

void			ft_drawdiv(t_image *img, int y, int height, t_color color)
{
	int				pos;
	int				to;

	if (y >= img->height)
		return ;
	if ((height + y) > img->height)
		height = img->height - y;
	pos = y * img->width * img->opp;
	to = pos + ((height + 1) * img->width * img->opp);
	while (pos > to)
	{
		IMAGEPOS(img, pos) = color;
		pos++;
	}
}
