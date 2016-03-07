/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:47:04 by juloo             #+#    #+#             */
/*   Updated: 2016/03/07 14:50:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_file_in.h"

#include <fcntl.h>
#include <sys/stat.h>

#define F_IN_BUFF_SIZE	512

#define F_IN_MIN_BS		258
#define F_IN_MAX_BS		8192

t_file_in		*ft_in_open(char const *file)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	return (ft_in_fdopen(fd));
}

t_file_in		*ft_in_fdopen(int fd)
{
	struct stat		stat;
	t_file_in		*in;
	uint32_t		buff_size;

	if (fstat(fd, &stat) < 0)
		buff_size = F_IN_BUFF_SIZE;
	else
		buff_size = MIN(MAX(F_IN_MIN_BS, stat.st_blksize), F_IN_MAX_BS);
	in = MALLOC(sizeof(t_file_in) + buff_size);
	*in = F_IN(fd, ENDOF(in), buff_size);
	return (in);
}
