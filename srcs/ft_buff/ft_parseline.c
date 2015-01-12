/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:13:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 21:18:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_parseline(t_buff *buff)
{
	char			c;
	t_string		line;

	ft_stringini(&line);
	c = ft_buffget(buff);
	while (c != EOF)
	{
		if ((c = ft_buffget(buff)) == '\n' || c == EOF)
			break ;
		ft_stringaddc(&line, c);
		buff->i++;
	}
	return (line);
}
