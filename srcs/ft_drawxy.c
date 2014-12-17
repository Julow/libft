/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawxy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:40:16 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 16:40:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawxy(t_image *img, int x, int y, t_color color)
{
	int				pos;
	int				i;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	if (ALPHA(color))
		ft_resalpha(&color, ft_imagept(img, PT(x, y)));
	pos = (img->width * y + x) * img->opp;
	i = -1;
	while (++i < img->opp)
	{
		img->data[pos + i] = color.b.b;
		color.i = color.i >> 8;
	}
}
