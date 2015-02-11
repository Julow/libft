/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:28:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 10:34:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_parsesubf(t_buff *buff, t_bool (*f)(char c))
{
	char			c;
	t_string		sub;

	ft_stringini(&sub);
	c = BG(buff);
	while (c != '\0')
	{
		if (!f((c = BG(buff))))
			break ;
		ft_stringaddc(&sub, c);
		buff->i++;
	}
	return (sub);
}
