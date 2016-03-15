/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:54:35 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/15 11:34:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

# include "ft/libft.h"

typedef struct s_img		t_img;

/*
** ========================================================================== **
** Img
** -
** IMG_PIXEL(IMG+, X, Y)	Get/set a pixel at X, Y
*/

struct			s_img
{
	uint32_t		*data;
	uint32_t		width;
	uint32_t		height;
};

# define IMG_PIXEL(IMG,X,Y)		(IMG).data[(IMG).width * (Y) + (X)]

/*
** Apply 'f' to each pixel of the image
*/
void			ft_img_map(t_img *img, uint32_t (*f)(uint32_t pixel));

#endif
