/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_out.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:09:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 11:30:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OUT_H
# define FILE_OUT_H

# include "ft/ft_out.h"
# include "ft/libft.h"

typedef struct s_file_out	t_file_out;

/*
** ========================================================================== **
** File out
*/

struct			s_file_out
{
	t_out			out;
	int				fd;
	bool			opened;
};

# define FILE_OUT_BUFF_SIZE	512

/*
** do the same for file_in
*/
t_file_out		*ft_out_open(t_sub file);

/*
** Create a file out from a fd
*/
t_file_out		*ft_out_fdopen(int fd);

/*
** Close a file out
** Do not close the file descriptor if it was created by ft_out_fdopen
*/
void			ft_out_close(t_file_out *out);

#endif
