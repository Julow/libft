/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawpt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:51:49 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 15:51:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

void			ft_drawpt(t_image *img, t_pt pt, t_color color)
{
	int				pos;
	int				i;

	if (pt.x < 0 || pt.x >= img->width || pt.y < 0 || pt.y >= img->height)
		return ;
	pos = (img->width * pt.y + pt.x) * img->opp;
	i = -1;
	while (++i < img->opp)
	{
		img->data[pos + i] = color.b.b;
		color.i = color.i >> 8;
	}
}
