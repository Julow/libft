/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 08:15:56 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/12 23:46:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/color_utils.h"

/*
** out_a = src_a + (dst_a * (1 - src_a))
** out_rgb = (src_rgb * src_a + (dst_rgb * dst_a * (1 - src_a))) / out_a
*/

uint32_t		color32_blend(uint32_t dst, uint32_t src)
{
	uint32_t const	src_fact = COLOR32_A(src) * 255;
	uint32_t const	out_a = COLOR32_A(dst) * (255 - COLOR32_A(src)) + src_fact;
	uint32_t const	dst_fact = COLOR32_A(dst) * (255 - COLOR32_A(src));

	return (COLOR32(out_a / 255,
		(COLOR32_R(src) * src_fact + (COLOR32_R(dst) * dst_fact)) / out_a,
		(COLOR32_G(src) * src_fact + (COLOR32_G(dst) * dst_fact)) / out_a,
		(COLOR32_B(src) * src_fact + (COLOR32_B(dst) * dst_fact)) / out_a));
}

void			colorf_blend(t_vec4 *color, t_vec4 const *src)
{
	float const		out_a = src->w + (color->w * (1.f - src->w));
	float const		src_fact = src->w / out_a;
	float const		dst_fact = color->w * (1.f - src->w) / out_a;

	color->x = src->x * src_fact + (color->x * dst_fact);
	color->y = src->y * src_fact + (color->y * dst_fact);
	color->z = src->z * src_fact + (color->z * dst_fact);
	color->w = out_a;
}
