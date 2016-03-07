/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:43:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/07 14:49:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getkey_internal.h"

#include <unistd.h>
#include <sys/select.h>

char			next_char(int fd)
{
	fd_set			fdr;
	char			c;

	FD_ZERO(&fdr);
	FD_SET(fd, &fdr);
	if (select(fd + 1, &fdr, NULL, NULL, &(struct timeval)GETKEY_MAX_WAIT) < 0)
		return (EOF);
	if (FD_ISSET(fd, &fdr))
	{
		if (read(fd, &c, 1) <= 0)
			return (EOF);
		return (c);
	}
	return ('\0');
}
