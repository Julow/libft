/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:23:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 17:06:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_out.h"
#include <unistd.h>

int				ft_flush(t_out *out)
{
	int				tmp;

	if (out->i <= 0 || out->flags & OUT_DSTR)
		return (0);
	if (out->flags & OUT_NOFLUSH)
		tmp = out->i;
	else
		tmp = write(out->fd, out->buff, out->i);
	out->i = 0;
	return (tmp);
}
