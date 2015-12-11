/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:43:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/11 12:38:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getkey_internal.h"
#include <unistd.h>
#include <sys/select.h>

// #define GETKEY_DEBUG
#ifdef GETKEY_DEBUG
# define DEBUG(...)		ft_dprintf(2, ##__VA_ARGS__)
#else
# define DEBUG(...)		VOID
#endif

char			next_char(int fd)
{
	fd_set			fdr;
	char			c;

	FD_ZERO(&fdr);
	FD_SET(fd, &fdr);
	if (select(fd + 1, &fdr, NULL, NULL, &(struct timeval)GETKEY_MAX_WAIT) < 0)
	{
		DEBUG("NEXT CHAR: TIMEOUT%n");
		return (EOF);
	}
	if (FD_ISSET(fd, &fdr))
	{
		if (read(fd, &c, 1) <= 0)
		{
			DEBUG("NEXT CHAR: FAIL%n");
			return (EOF);
		}
		DEBUG("NEXT CHAR: %d '%c'%n", c, c);
		return (c);
	}
	DEBUG("NEXT CHAR: 0%n");
	return ('\0');
}
