/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:36:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/02 18:42:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "ft/libft.h"

/*
** ========================================================================== **
** Path
*/

/*
** Return the file name component of path
** Put the dir name into 'dirname' if not NULL
*/
t_sub			ft_path_split(t_sub path, t_sub *dirname);

/*
** Return the file extension
** Put the file name without extension into 'basename' if not NULL
*/
t_sub			ft_path_ext(t_sub path, t_sub *basename);

#endif
