/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsewhite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:29:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 23:26:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_parsewhite(t_buff *buff)
{
	if (!BIF(buff, &ft_iswhite))
		return (false);
	while (ft_iswhite(BG(buff)))
		buff->i++;
	return (true);
}
