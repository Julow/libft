/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:25:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 14:54:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_resalpha(t_color *c, t_color bg)
{
	t_big			delta;

	if (INVI(*c))
	{
		*c = bg;
		return ;
	}
	delta = BIG(c->b.a) / 255;
	c->b.a = 0;
	c->b.r = ft_mix(c->b.r, bg.b.r, delta);
	c->b.g = ft_mix(c->b.g, bg.b.g, delta);
	c->b.b = ft_mix(c->b.b, bg.b.b, delta);
}
