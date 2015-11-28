/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsewhite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:29:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

t_bool			ft_parsewhite(t_buff *buff)
{
	if (!IS(BG(buff), IS_WHITE))
		return (false);
	BR(buff);
	while (IS(BG(buff), IS_WHITE))
		buff->i++;
	return (true);
}
