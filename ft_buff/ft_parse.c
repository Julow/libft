/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 17:02:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

t_bool			ft_parse(t_buff *buff, const char *parse)
{
	if (ft_strchr(parse, BG(buff)) == NULL)
		return (false);
	buff->i++;
	while (!BEOF(buff))
	{
		if (ft_strchr(parse, BG(buff)) == NULL)
			break ;
		buff->i++;
	}
	return (true);
}
