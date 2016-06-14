/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:05:31 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 19:08:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "ft/libft.h"

/*
** ========================================================================== **
** File functions
*/

/*
** Wrapper for the open syscall
** The default mode is 0644
*/
int				ft_open(t_sub file, uint32_t o_flags);

#endif
