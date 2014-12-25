/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 20:24:30 by juloo             #+#    #+#             */
/*   Updated: 2014/12/25 20:24:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawtri(t_image *img, t_pt pts[3], t_color color)
{
	ft_drawline(img, pts[0], pts[1], color);
	ft_drawline(img, pts[0], pts[2], color);
	ft_drawline(img, pts[1], pts[2], color);
}
