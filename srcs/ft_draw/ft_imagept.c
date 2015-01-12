/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imagept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:11:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:25:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_color	ft_imagept(t_image *img, t_pt pt)
{
	t_color			c;
	int				pos;
	int				i;

	c = C(0xFF000000);
	if (pt.x < 0 || pt.x >= img->width || pt.y < 0 || pt.y >= img->height)
		return (c);
	pos = img->l_size * pt.y + (pt.x * img->opp);
	i = -1;
	while (++i < img->opp)
	{
		c.u = c.u >> 8;
		c.b.a = img->data[pos + i];
	}
	c.u = c.u << (4 - img->opp);
	return (c);
}
