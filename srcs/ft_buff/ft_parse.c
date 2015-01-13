/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/13 15:33:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parse(t_buff *buff, const char *parse)
{
	char			c;

	c = ft_buffget(buff);
	while (c != '\0')
	{
		if (ft_strchr(parse, (c = ft_buffget(buff))) == NULL)
			break ;
		buff->i++;
	}
}
