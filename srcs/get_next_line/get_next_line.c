/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:23:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 22:51:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>
#include <unistd.h>

static t_gnlfd	*get_gnlfd(int const fd)
{
	static t_gnlfd	*gnlfd_list = NULL;
	t_gnlfd			*tmp;

	tmp = gnlfd_list;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if ((tmp = MAL1(t_gnlfd)) == NULL)
		return (NULL);
	*tmp = (t_gnlfd){NULL, fd, 0, 0, 0, gnlfd_list};
	gnlfd_list = tmp;
	return (tmp);
}

static int		buff_read(t_gnlfd *gnlfd)
{
	char			*tmp;
	int				len;

	if ((tmp = MAL(char, gnlfd->length + GNL_BUFF + 1)) == NULL)
		return (-1);
	ft_memcpy(tmp, gnlfd->buff, gnlfd->length);
	if (gnlfd->buff != NULL)
		free(gnlfd->buff - gnlfd->offset);
	gnlfd->buff = tmp;
	len = read(gnlfd->fd, tmp + gnlfd->length, GNL_BUFF);
	tmp[gnlfd->length + GNL_BUFF] = '\0';
	gnlfd->length += (len < 0) ? 0 : len;
	gnlfd->offset = 0;
	return (len);
}

static int		buff_cut(t_gnlfd *gnlfd, int len, t_sub *dst, int rem)
{
	gnlfd->buff[len] = '\0';
	dst->str = gnlfd->buff;
	dst->length = len;
	len += rem;
	gnlfd->offset += len;
	gnlfd->buff += len;
	gnlfd->length -= len;
	gnlfd->i -= len;
	return (GNL_SUCCES);
}

int				get_next_line(int const fd, t_sub *line)
{
	t_gnlfd			*gnl;
	int				len;

	if (fd >= 0 && line != NULL && (gnl = get_gnlfd(fd)) != NULL)
		while (1)
		{
			gnl->i--;
			while (++(gnl->i) < gnl->length)
				if (gnl->buff[gnl->i] == '\n' || gnl->buff[gnl->i] == EOF)
					return (buff_cut(gnl, gnl->i, line, 1));
			if ((len = buff_read(gnl)) < 0)
				break ;
			if (len == 0 && gnl->length == 0)
				return (*line = SUB(NULL, 0), free(gnl->buff - gnl->offset),
				*gnl = (t_gnlfd){NULL, fd, 0, 0, 0, gnl->next}, GNL_EOF);
			if (len == 0)
				return (buff_cut(gnl, gnl->length, line, 0));
		}
	return (GNL_ERROR);
}
