/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:12:44 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 19:17:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_IN_H
# define FILE_IN_H

# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_file_in	t_file_in;

/*
** ========================================================================== **
** File input stream
*/

struct		s_file_in
{
	t_in		in;
	char		*buff;
	uint32_t	buff_size;
	int			fd;
	bool		opened;
};

t_file_in	*ft_in_open(t_sub file);
t_file_in	*ft_in_fdopen(int fd);

void		ft_in_close(t_file_in *in);

/*
** TODO: private
*/

# define F_IN_BUFF_SIZE	512

# define F_IN(FD,B,S)	((t_file_in){IN(B, 0, &file_in_refresh),B,S,FD,false})

bool		file_in_refresh(t_file_in *in);

#endif
