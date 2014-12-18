/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imageput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 14:55:40 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/18 14:55:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_imageput(t_image *img, int pos, t_color color)
{
	int				to;

	to = pos + img->opp;
	while (pos < to)
	{
		img->data[pos] = color.b.b;
		color.i >>= 8;
		pos++;
	}
}
