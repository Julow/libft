/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:27:30 by juloo             #+#    #+#             */
/*   Updated: 2016/04/03 11:03:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_in.h"
#include "ft/img_loader.h"
#include "ft/libft.h"

#include "internal.h"

#define AT(t,p,i)			((t*)(((void*)(p)) + (i)))

#define HEADER_SIZE			18

#define OFFSET_CM_TYPE		1
#define OFFSET_IMG_TYPE		2
#define OFFSET_PIX_SIZE		16
#define OFFSET_WIDTH		12
#define OFFSET_HEIGHT		14

static bool		read_pixels(t_in *in, t_img *dst, uint32_t size, uint32_t bps)
{
	uint8_t					*tmp;
	const uint8_t *const	end = (uint8_t*)dst->data + size;
	uint32_t						i;

	tmp = (uint8_t*)dst->data;
	while (tmp < end)
	{
		i = 0;
		while (i < bps)
		{
			if (!IN_REFRESH(in))
				return (false);
			tmp[i++] = in->buff[in->buff_i++];
		}
		if (i < 4)
		{
			while (i < 3)
				tmp[i++] = tmp[0];
			tmp[i++] = (uint8_t)-1;
		}
		tmp += 4;
	}
	return (true);
}

bool			load_tga_image(t_in *in, t_img *dst)
{
	uint8_t			header[HEADER_SIZE];
	uint32_t		bps;
	uint32_t		img_type;

	if (!ft_read(in, (void*)header, HEADER_SIZE))
		return (false);
	bps = *AT(uint8_t, header, OFFSET_PIX_SIZE) / 8;
	img_type = *AT(uint8_t, header, OFFSET_IMG_TYPE);
	if (!(*AT(uint8_t, header, OFFSET_CM_TYPE) == 0
		&& ((img_type == 3 && bps == 1)
			|| (img_type == 2 && (bps == 4 || bps == 3)))))
		return (false);
	dst->width = *AT(short, header, OFFSET_WIDTH);
	dst->height = *AT(short, header, OFFSET_HEIGHT);
	dst->data = NEW_N(uint32_t, dst->width * dst->height);
	return (read_pixels(in, dst, dst->width * dst->height * 4, bps));
}
