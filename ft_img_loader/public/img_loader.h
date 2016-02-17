/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:16:16 by juloo             #+#    #+#             */
/*   Updated: 2016/02/17 11:54:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMAGE_LOADER_H
# define FT_IMAGE_LOADER_H

# include "ft/img.h"
# include "ft/libft.h"

/*
** ========================================================================== **
** Image loader
** -
** Supported formats:
** .tga		24 or 32 bits		no color map and no compression
** -
** Output 32 bits color map
*/

/*
** dst->data is allocated and can be free using free() function
** -
** Return true on success, false on error
*/
bool			ft_load_img(char const *file_name, t_img *dst);

#endif
