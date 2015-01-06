/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:49:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/06 23:05:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNAL_H
# define FT_INTERNAL_H

# include "libft.h"

# define PUTNBR_BUFF	11
# define PUTLONG_BUFF	21

# define GNL_BUFF		192

# define GNL_SUCCES		1
# define GNL_EOF		0
# define GNL_ERROR		-1

typedef struct	s_gnlfd
{
	char			*buff;
	int				fd;
	int				length;
	int				offset;
	int				i;
	struct s_gnlfd	*next;
}				t_gnlfd;

#endif
