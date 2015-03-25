/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawpt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:51:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 15:27:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_drawpt(t_image *img, t_pt pt, t_color color)
{
	if (pt.x < 0 || pt.x >= img->width || pt.y < 0 || pt.y >= img->height)
		return ;
	if (ALPHA(color))
		ft_resalpha(&color, IMAGEPT(img, pt.x, pt.y));
	IMAGEPT(img, pt.x, pt.y) = color;
}
