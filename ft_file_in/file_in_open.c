/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:47:04 by juloo             #+#    #+#             */
/*   Updated: 2016/06/14 19:20:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file.h"
#include "ft/file_in.h"

#include <fcntl.h>

t_file_in		*ft_in_open(t_sub file)
{
	int				fd;
	t_file_in		*in;

	if ((fd = ft_open(file, O_RDONLY)) < 0)
		return (NULL);
	in = ft_in_fdopen(fd);
	in->opened = true;
	return (in);
}

t_file_in		*ft_in_fdopen(int fd)
{
	t_file_in		*in;

	in = MALLOC(sizeof(t_file_in) + F_IN_BUFF_SIZE);
	*in = F_IN(fd, ENDOF(in), F_IN_BUFF_SIZE);
	return (in);
}
