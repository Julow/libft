/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:29:46 by juloo             #+#    #+#             */
/*   Updated: 2016/03/07 14:50:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_LOADER_H
# define IMG_LOADER_H

# include "ft/ft_in.h"
# include "ft/img_loader.h"

typedef struct	s_imgtype
{
	t_sub			ext;
	bool			(*f)(t_in *in, t_img *dst);
}				t_imgtype;

bool			load_tga_image(t_in *in, t_img *dst);

#endif
