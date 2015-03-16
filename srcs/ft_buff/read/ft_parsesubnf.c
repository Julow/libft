/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubnf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:20:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 23:32:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_parsesubnf(t_buff *buff, t_string *dst, t_bool (*f)(int))
{
	char			c;
	int				len;

	len = dst->length;
	while (!BEOF(buff))
	{
		c = BG(buff);
		if (f(c))
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
	return (dst->length - len);
}
