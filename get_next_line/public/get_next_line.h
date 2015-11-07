/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 14:52:05 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 14:54:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

/*
** ========================================================================== **
** get_next_line
** --
** Read a file per line
*/

# define GNL_SUCCES		1
# define GNL_EOF		0
# define GNL_ERROR		-1

int				get_next_line(int const fd, t_sub *line);

#endif
