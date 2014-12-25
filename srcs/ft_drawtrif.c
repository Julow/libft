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
	t_pos			delta;
	double			*x;
	t_pt			middle;
	int				y;

	sortpts(&pts, 3);
	if (pts[1].y == pts[2].y || pts[0].y == pts[1].y)
		middle = (pts[1].y == pts[2].y) ? pts[2] : pts[0];
	else
		middle = PT(ROUND((double)(pts[1].y - pts[0].y) / (double)(pts[2].y -
			pts[0].y) * (double)(pts[2].x - pts[0].x)) + pts[0].x, pts[1].y);
	delta = POS((double)(pts[1].x - pts[0].x) / (double)(pts[1].y - pts[0].y),
		(double)(middle.x - pts[0].x) / (double)(middle.y - pts[0].y), 0);
	x = (double[2]){pts[0].x, pts[0].x};
	y = pts[0].y;
	while (++y <= pts[1].y)
		ft_drawnpt(img, PT(ROUND(x[0] += delta.x), y),
			ROUND((x[1] += delta.y) - x[0]), color);
	delta = POS((double)(pts[2].x - pts[1].x) / (double)(pts[2].y - pts[1].y),
		(double)(pts[2].x - middle.x) / (double)(pts[2].y - middle.y), 0);
	x = (double[2]){pts[1].x, middle.x};
	y = middle.y;
	while (++y < pts[2].y)
		ft_drawnpt(img, PT(ROUND(x[0] += delta.x), y),
			ROUND((x[1] += delta.y) - x[0]), color);
}
