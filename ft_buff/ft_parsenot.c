/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:04:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/08 20:17:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

t_bool			ft_parsenot(t_buff *buff, const char *parse)
{
	if (ft_strchri(parse, BG(buff)) != NULL)
		return (false);
	buff->i++;
	while (!BEOF(buff))
	{
		if (ft_strchri(parse, BG(buff)) != NULL)
			break ;
		buff->i++;
	}
	return (true);
}
