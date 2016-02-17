/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:54:35 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/17 11:56:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

# include "ft/libft.h"

typedef struct s_img		t_img;

/*
** ========================================================================== **
** Img
*/

struct			s_img
{
	uint32_t		*data;
	uint32_t		width;
	uint32_t		height;
};

#endif
