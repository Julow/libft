/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:28:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 17:05:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parsesubf(t_buff *buff, t_string *dst, t_bool (*f)(int))
{
	char			c;

	ft_stringini(dst);
	c = BG(buff);
	while (c != '\0')
	{
		if (!f((c = BG(buff))))
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
}
