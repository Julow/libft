/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:04:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 23:48:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_parsenot(t_buff *buff, const char *parse)
{
	if (ft_strchr(parse, BG(buff)) != NULL)
		return (false);
	buff->i++;
	while (!BEOF(buff))
	{
		if (ft_strchr(parse, BG(buff)) != NULL)
			break ;
		buff->i++;
	}
	return (true);
}
