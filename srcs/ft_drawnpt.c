/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawnpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:40:11 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 16:40:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawnpt(t_image *img, t_pt pt, int n, t_color color)
{
	int				pos;
	int				i;
	t_color			tmp;

	if (pt.x < 0 || pt.x >= img->width || pt.y < 0 || pt.y >= img->height)
		return ;
	pos = (img->width * pt.y + pt.x) * img->opp;
	n *= img->opp;
	while (n >= 0)
	{
		tmp = color;
		if (ALPHA(tmp))
			ft_resalpha(&tmp, ft_imagept(img, pt));
		i = -1;
		while (++i < img->opp)
		{
			img->data[pos + n + i] = tmp.b.b;
			tmp.i = tmp.i >> 8;
		}
		n -= img->opp;
	}
}
