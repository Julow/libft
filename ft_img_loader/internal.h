/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:29:46 by juloo             #+#    #+#             */
/*   Updated: 2016/03/14 12:04:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/ft_in.h"
# include "ft/img.h"
# include "ft/img_loader.h"
# include "ft/libft.h"

typedef struct	s_imgtype
{
	t_sub			ext;
	bool			(*f)(t_in *in, t_img *dst);
}				t_imgtype;

bool			load_tga_image(t_in *in, t_img *dst);

#endif
