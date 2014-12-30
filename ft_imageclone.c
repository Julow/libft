/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imageclone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 15:08:27 by juloo             #+#    #+#             */
/*   Updated: 2014/12/20 15:08:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_image			*ft_imageclone(t_image *img)
{
	t_image			*clone;

	clone = MAL1(t_image);
	clone->data = MAL(t_uchar, img->width * img->height * img->opp);
	clone->img = img->img;
	clone->width = img->width;
	clone->height = img->height;
	clone->l_size = img->l_size;
	clone->opp = img->opp;
	clone->endian = img->endian;
	return (clone);
}
