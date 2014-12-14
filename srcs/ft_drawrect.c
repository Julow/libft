/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:47:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 14:47:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawrect(t_image *img, t_pt p1, t_pt p2, t_color color)
{
	ft_resrect(&p1, &p2);
	ft_drawnpt(img, p1, p2.x - p1.x, color);
	ft_drawnpt(img, PT(p1.x, p2.y), p2.x - p1.x, color);
	while (p1.y < p2.y)
	{
		ft_drawpt(img, p1, color);
		ft_drawpt(img, PT(p2.x, p1.y), color);
		p1.y++;
	}
}
