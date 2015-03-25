/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawdiv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 15:18:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 15:21:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
