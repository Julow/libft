/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawnpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:40:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 15:21:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawnpt(t_image *img, t_pt pt, int n, t_color color)
{
	int				pos;
	t_color			tmp;

	if (n < 0)
		pt.x -= (n = -n);
	if (pt.x < 0)
	{
		n += pt.x;
		pt.x = 0;
	}
	if (n <= 0 || pt.x >= img->width || pt.y < 0 || pt.y >= img->height)
		return ;
	pos = (img->width * pt.y + pt.x) * img->opp;
	n *= img->opp;
	while (n >= 0)
	{
		tmp = color;
		if (ALPHA(tmp))
			ft_resalpha(&tmp, IMAGEPOS(img, pos));
		IMAGEPOS(img, pos) = tmp;
		n -= img->opp;
		pos += img->opp;
	}
}
