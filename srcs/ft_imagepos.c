/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imagepos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 19:14:11 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/17 19:14:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color			ft_imagepos(t_image *img, int pos)
{
	t_color			c;
	int				i;

	c = C(0xFF000000);
	i = -1;
	while (++i < img->opp)
	{
		c.u = c.u >> 8;
		c.b.a = img->data[pos + i];
	}
	c.u = c.u << (4 - img->opp);
	return (c);
}
