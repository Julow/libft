/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:27:30 by juloo             #+#    #+#             */
/*   Updated: 2016/03/14 12:04:45 by jaguillo         ###   ########.fr       */
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

static bool		read_pixels(t_in *in, t_img *dst, int size, int pixel_size)
{
	uint8_t					*tmp;
	const uint8_t *const	end = (uint8_t*)dst->data + size;
	int						i;

	tmp = (uint8_t*)dst->data;
	while (tmp < end)
	{
		i = 0;
		while (i < pixel_size)
		{
			if (!IN_REFRESH(in))
				return (false);
			tmp[i++] = in->buff[in->buff_i++];
		}
		while (i < 4)
			tmp[i++] = (uint8_t)-1;
		tmp += 4;
	}
	return (true);
}

bool			load_tga_image(t_in *in, t_img *dst)
{
	uint8_t			header[HEADER_SIZE];
	int				pixel_size;

	if (!ft_read(in, (void*)header, HEADER_SIZE))
		return (false);
	pixel_size = (int)*AT(uint8_t, header, OFFSET_PIX_SIZE);
	if (*AT(uint8_t, header, OFFSET_CM_TYPE) != 0
		|| *AT(uint8_t, header, OFFSET_IMG_TYPE) != 2
		|| (pixel_size != 32 && pixel_size != 24))
		return (false);
	dst->width = (int)*AT(short, header, OFFSET_WIDTH);
	dst->height = (int)*AT(short, header, OFFSET_HEIGHT);
	dst->data = NEW_N(uint32_t, dst->width * dst->height);
	return (read_pixels(in, dst, dst->width * dst->height * 4, pixel_size / 8));
}
