/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubnf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:20:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/25 00:04:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_parsesubnf(t_buff *buff, t_bool (*f)(int))
{
	char			c;
	t_string		sub;

	ft_stringini(&sub);
	c = BG(buff);
	while (c != '\0')
	{
		if (f((c = BG(buff))))
			break ;
		ft_stringaddc(&sub, c);
		buff->i++;
	}
	return (sub);
}
