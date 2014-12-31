/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtrif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 20:24:17 by juloo             #+#    #+#             */
/*   Updated: 2014/12/25 20:24:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sortpts(t_pt **pts, int n)
{
	int				i;
	int				j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if ((*pts)[i].y > (*pts)[j].y)
				ft_memswap(*pts + i, *pts + j, sizeof(t_pt));
			else if ((*pts)[i].y == (*pts)[j].y && (*pts)[i].x > (*pts)[j].x)
				ft_memswap(*pts + i, *pts + j, sizeof(t_pt));
	}
}

void			ft_drawtrif(t_image *img, t_pt pts[3], t_color color)
{
	double			delta[2];
	double			*x;
	t_pt			middle;
	int				y;

	sortpts(&pts, 3);
	if (pts[1].y == pts[2].y || pts[0].y == pts[1].y)
		middle = (pts[1].y == pts[2].y) ? pts[2] : pts[0];
	else
		middle = PT(DOWN((double)(pts[1].y - pts[0].y) / (double)(pts[2].y -
			pts[0].y) * (double)(pts[2].x - pts[0].x)) + pts[0].x, pts[1].y);
	delta[0] = (double)(pts[1].x - pts[0].x) / (double)(pts[1].y - pts[0].y);
	delta[1] = (double)(middle.x - pts[0].x) / (double)(middle.y - pts[0].y);
	x = (double[2]){pts[0].x, pts[0].x};
	y = pts[0].y;
	while (++y <= pts[1].y)
		ft_drawnpt(img, PT(ROUND(x[0]), y), ROUND(x[1] += delta[1]) -
			ROUND(x[0] += delta[0]), color);
	delta[0] = (double)(pts[2].x - pts[1].x) / (double)(pts[2].y - pts[1].y);
	delta[1] = (double)(pts[2].x - middle.x) / (double)(pts[2].y - middle.y);
	x = (double[2]){pts[2].x, pts[2].x};
	y = pts[2].y + 1;
	while (--y > middle.y)
		ft_drawnpt(img, PT(ROUND(x[0]), y), ROUND(x[1] -= delta[1]) -
			ROUND(x[0] -= delta[0]), color);
}
