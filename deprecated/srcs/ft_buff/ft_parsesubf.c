/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:28:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:58:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_string.h"

int				ft_parsesubf(t_buff *buff, t_string *dst, t_bool (*f)(int))
{
	char			c;
	int				len;

	len = dst->length;
	while (!BEOF(buff))
	{
		c = BG(buff);
		if (!f(c))
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
	return (dst->length - len);
}
