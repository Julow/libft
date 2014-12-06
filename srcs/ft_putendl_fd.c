/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:51:37 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 17:51:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putendl_fd(char *s, int fd)
{
	int				length;

	length = ft_strlen(s);
	s[length] = '\n';
	(void)(1 + write(fd, s, length + 1));
	s[length] = '\0';
}
