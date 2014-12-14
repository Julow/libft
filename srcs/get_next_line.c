/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 17:18:43 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/18 17:18:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_internal.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static t_gnl	*gnl_getgnl(int const fd)
{
	static t_gnl	*gnls = NULL;
	t_gnl			*tmp;

	tmp = gnls;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = MAL1(t_gnl);
	if (tmp != NULL)
	{
		tmp->fd = fd;
		tmp->buff = NULL;
		tmp->next = gnls;
		gnls = tmp;
	}
	if (tmp->buff == NULL)
		tmp->buff = ft_stringnew();
	return (tmp);
}

static int		gnl_sub(t_string *buff, int len, char **line)
{
	int				i;

	*line = MAL(char, len + 1);
	if (*line == NULL)
		return (GNL_ERROR);
	i = 0;
	while (i < len)
	{
		(*line)[i] = buff->content[i];
		i++;
	}
	(*line)[i] = '\0';
	ft_stringrem(buff, 0, len + 1);
	return ((i > 0) ? GNL_SUCCES : GNL_END);
}

static int		gnl_read(int const fd, t_string *str)
{
	int				len;
	char			*buff;

	buff = MAL(char, GNL_BUFF);
	if (buff == NULL)
		return (GNL_ERROR);
	len = read(fd, buff, GNL_BUFF);
	ft_stringaddl(str, buff, len);
	free(buff);
	return (len);
}

void			gnl_clear_cache(int const fd)
{
	t_gnl			*gnl;

	gnl = gnl_getgnl(fd);
	if (gnl->buff != NULL)
		ft_stringkil(gnl->buff);
	gnl->buff = NULL;
}

int				get_next_line(int const fd, char **line)
{
	t_gnl			*gnl;
	char			*tmp;
	int				len;
	int				i;

	len = 1;
	i = 0;
	gnl = gnl_getgnl(fd);
	while (fd >= 0 && line != NULL && gnl != NULL && gnl->buff != NULL)
	{
		tmp = gnl->buff->content;
		while (tmp[i] != '\n' && tmp[i] != '\0' && tmp[i] != EOF)
			i++;
		if (tmp[i] == '\0' && (len = gnl_read(fd, gnl->buff)) > 0)
			continue;
		if (gnl_sub(gnl->buff, i, line) <= 0 && len <= 0)
		{
			ft_stringkil(gnl->buff);
			gnl->buff = NULL;
			return (GNL_END);
		}
		return (GNL_SUCCES);
	}
	return (GNL_ERROR);
}
