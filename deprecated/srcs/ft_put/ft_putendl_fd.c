/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:51:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:32:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

inline int		ft_putendl_fd(const char *s, int fd)
{
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}
