/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:48:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:50:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawline(t_image *img, t_pt p1, t_pt p2, t_color color)
{
	t_pt			delta;
	t_pt			dirr;
	int				err;

	delta = PT(ABS(p2.x - p1.x), -ABS(p2.y - p1.y));
	dirr = PT((p1.x < p2.x) ? 1 : -1, (p1.y < p2.y) ? 1 : -1);
	err = (delta.x + delta.y) * 2;
	while (true)
	{
		ft_drawpt(img, p1, color);
		if (err >= delta.y)
		{
			if (p1.x == p2.x)
				break ;
			err += delta.y * 2;
			p1.x += dirr.x;
		}
		if (err <= delta.x)
		{
			if (p1.y == p2.y)
				break ;
			err += delta.x * 2;
			p1.y += dirr.y;
		}
	}
}
