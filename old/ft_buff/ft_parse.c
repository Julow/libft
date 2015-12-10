/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

bool			ft_parse(t_buff *buff, const char *parse)
{
	if (ft_strchri(parse, BG(buff)) < 0)
		return (false);
	buff->i++;
	while (!BEOF(buff))
	{
		if (ft_strchri(parse, BG(buff)) < 0)
			break ;
		buff->i++;
	}
	return (true);
}
