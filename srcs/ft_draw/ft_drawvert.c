/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:45:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 15:15:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawvert(t_image *img, t_pt pt, int height, t_color color)
{
	int				pos;
	t_color			tmp;

	if (pt.y < 0)
	{
		height += pt.y;
		pt.y = 0;
	}
	if ((pt.y + height) > img->height)
		height = img->height - pt.y;
	if (pt.x < 0 || pt.x >= img->width || height <= 0 || pt.y >= img->height)
		return ;
	pos = (img->width * pt.y + pt.x) * img->opp;
	while (height-- > 0)
	{
		tmp = color;
		if (ALPHA(tmp))
			ft_resalpha(&tmp, IMAGEPOS(img, pos));
		IMAGEPOS(img, pos) = tmp;
		pos += img->width * img->opp;
	}
}
