/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubnf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:20:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 16:51:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parsesubnf(t_buff *buff, t_string *dst, t_bool (*f)(int))
{
	char			c;

	ft_stringini(dst);
	c = BG(buff);
	while (c != '\0')
	{
		if (f((c = BG(buff))))
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
}
