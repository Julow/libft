/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 23:08:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/21 20:24:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff			*ft_out(void)
{
	static char		buffer[FTOUT_BUFF] = DB(FTOUT_BUFF, 0);
	static t_buff	out = (t_buff){buffer, 0, FTOUT_BUFF, 1};

	return (&out);
}
