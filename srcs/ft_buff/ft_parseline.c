/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:13:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 10:35:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_parseline(t_buff *buff)
{
	char			c;
	t_string		line;

	ft_stringini(&line);
	c = BG(buff);
	while (c != '\0')
	{
		if ((c = BG(buff)) == '\n' || c == '\0')
			break ;
		ft_stringaddc(&line, c);
		buff->i++;
	}
	if (c == '\n')
		buff->i++;
	return (line);
}
