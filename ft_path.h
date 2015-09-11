/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 16:08:54 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:27:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PATH_H
# define FT_PATH_H

#include "libft.h"
#include "ft_dstr.h"

/*
** ========================================================================== **
** Path
*/

t_bool			ft_pathcurrent(t_dstr *path);

t_sub			ft_pathfile(t_sub path);

t_sub			ft_pathdir(t_sub path);

void			ft_pathclean(t_dstr *path); // TODO implement

void			ft_pathappend(t_dstr *path, t_sub add);

t_bool			ft_pathabsolute(t_dstr *path);
t_bool			ft_pathrelative(t_dstr *path);

#endif
