/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawxy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:40:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:26:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_drawxy(t_image *img, int x, int y, t_color color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	if (ALPHA(color))
		ft_resalpha(&color, ft_imagept(img, PT(x, y)));
	ft_imageput(img, (img->width * y + x) * img->opp, color);
}
