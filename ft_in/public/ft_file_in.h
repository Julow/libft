/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_in.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 00:09:35 by juloo             #+#    #+#             */
/*   Updated: 2015/12/06 12:50:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_IN_H
# define FT_FILE_IN_H

# include "ft/ft_in.h"

typedef struct s_file_in	t_file_in;

/*
** ========================================================================== **
** File input stream
*/

struct s_file_in
{
	t_in		in;
	char		*buff;
	uint32_t	buff_size;
	int			fd;
};

# define F_IN(FD,B,S)	((t_file_in){IN(B, 0, &file_in_refresh), B, S, FD})

t_file_in	*ft_in_open(char const *file);
t_file_in	*ft_in_fdopen(int fd);

void		ft_in_close(t_file_in *in);

t_bool		file_in_refresh(t_file_in *in);

#endif
