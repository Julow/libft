/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:56:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/15 10:57:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/img.h"

void			ft_img_map(t_img *img, uint32_t (*f)(uint32_t pixel))
{
	uint32_t const	end = img->width * img->height;
	uint32_t		i;

	i = 0;
	while (i < end)
	{
		img->data[i] = f(img->data[i]);
		i++;
	}
}
