/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawcirclef.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 02:01:06 by juloo             #+#    #+#             */
/*   Updated: 2014/12/14 02:01:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawcirclef(t_image *img, t_pt o, int radius, t_color color)
{
	t_pt			pt;
	int				err;

	pt = PT(-radius, 0);
	err = 2 - (2 * radius);
	while (pt.x <= 0)
	{
		ft_drawnpt(img, PT(o.x, o.y + pt.y), -pt.x, color);
		ft_drawnpt(img, PT(o.x - pt.y, o.y - pt.x), pt.y, color);
		ft_drawnpt(img, PT(o.x + pt.x, o.y - pt.y), -pt.x, color);
		ft_drawnpt(img, PT(o.x, o.y + pt.x), pt.y, color);
		radius = err;
		if (radius <= pt.y)
		{
			pt.y++;
			err += pt.y * 2 + 1;
		}
		if (radius > pt.x || err > pt.y)
		{
			pt.x++;
			err += pt.x * 2 + 1;
		}
	}
}
