/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:27:31 by juloo             #+#    #+#             */
/*   Updated: 2016/03/14 12:06:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_file_in.h"
#include "ft/img_loader.h"
#include "ft/libft.h"

#include "internal.h"

static t_imgtype const	g_imgtypes[] = {
	{SUBC(".tga"), &load_tga_image},
	{SUB("", 0), NULL}
};

bool			ft_load_img(char const *file_name, t_img *dst)
{
	t_sub			ext;
	int				i;
	t_file_in		*in;
	bool			ret;

	ext = ft_sub((char*)file_name, -1, -1);
	while (--(ext.str) >= file_name)
	{
		ext.length++;
		if (ext.str[0] == '.')
		{
			i = -1;
			while (g_imgtypes[++i].f != NULL)
				if (g_imgtypes[i].ext.length == ext.length
					&& !ft_memcmp(g_imgtypes[i].ext.str, ext.str, ext.length))
				{
					if ((in = ft_in_open(file_name)) == NULL)
						return (false);
					ret = g_imgtypes[i].f((void*)in, dst);
					ft_in_close(in);
					return (ret);
				}
		}
	}
	return (false);
}
