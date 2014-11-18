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

int				get_next_line(int const fd, char **line);

#endif
