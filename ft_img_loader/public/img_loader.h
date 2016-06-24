/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:16:16 by juloo             #+#    #+#             */
/*   Updated: 2016/06/25 01:39:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_LOADER_H
# define IMG_LOADER_H

# include "ft/img.h"
# include "ft/libft.h"

/*
** ========================================================================== **
** Image loader
** -
** Supported formats:
** .tga		8, 24 or 32 bits	no color palette and no compression
** -
** Output 32 bits color map
*/

/*
** dst->data is allocated and can be free using free() function
** -
** Return true on success, false on error
*/
bool			ft_load_img(t_sub file_name, t_img *dst);

#endif
