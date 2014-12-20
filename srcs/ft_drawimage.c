/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 15:08:09 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/20 15:08:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_drawimage(t_image *dst, t_image *src, t_pt pos, t_rect part)
{
	t_byte			*dstpos;
	t_byte			*srcpos;

	if (pos.x >= dst->width || pos.y >= dst->width || part.width <= 0
		|| part.height <= 0 || dst->opp != src->opp)
		return ;
	if (pos.x < 0)
		part.width += pos.x;
	if (pos.y < 0)
		part.height += pos.y;
	pos = PT((pos.x < 0) ? 0 : pos.x, (pos.y < 0) ? 0 : pos.y);
	if ((pos.x + part.width) > dst->width)
		part.width = dst->width - pos.x;
	if ((pos.y + part.height) > dst->height)
		part.height = dst->height - pos.y;
	part.width *= dst->opp;
	dstpos = dst->data + ((pos.y * (dst->width - 1) + pos.x) * dst->opp);
	srcpos = src->data + ((part.y * (src->width - 1) + part.x) * dst->opp);
	while (part.height-- > 0)
		ft_memmove(dstpos += dst->width * dst->opp,
			srcpos += src->width * src->opp, part.width);
}
