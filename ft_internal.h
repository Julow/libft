/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 00:01:56 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/15 00:01:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNAL_H
# define FT_INTERNAL_H

# define GNL_BUFF	256

# define GNL_SUCCES	1
# define GNL_END	0
# define GNL_ERROR	-1

typedef struct	s_gnl
{
	int				fd;
	t_string		*buff;
	struct s_gnl	*next;
}				t_gnl;

#endif
