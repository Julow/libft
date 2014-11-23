/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 17:13:11 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/18 17:13:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_BUFF	256

# ifndef EOF
#  define EOF		-1
# endif

# define GNL_SUCCES	1
# define GNL_END	0
# define GNL_ERROR	-1

typedef struct	s_gnl
{
	int				fd;
	t_string		*buff;
	struct s_gnl	*next;
}				t_gnl;

/*
** Read a file line per line.
** 'line' is not a buffer.
** =============
** Return GNL_SUCCES if a line is read,
** GNL_END if the end of file is reach
** GNL_ERROR if an error occured.
*/
int				get_next_line(int const fd, char **line);

/*
** Clear the cache relative to the fd.
** Call it after close a fd if the end of file is not reach
*/
void			gnl_clear_cache(int const fd);

#endif
