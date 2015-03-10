/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readbuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:15:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 18:26:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <unistd.h>
#include <stdlib.h>

/*
** Return the current char of the t_buff 'buff'
** Try to read if 'buff' is ended
** (only if 'buff' is a file buffer ('fd' >= 0))
** Return '\0' if the end of the buffer is reach
*/
inline char		ft_readbuff(t_buff *buff)
{
	char			c;

	c = BG(buff);
	buff->i++;
	return (c);
}
