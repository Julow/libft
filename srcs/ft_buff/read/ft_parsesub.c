/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 17:05:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parsesub(t_buff *buff, t_string *dst, const char *parse)
{
	char			c;

	ft_stringini(dst);
	c = BG(buff);
	while (c != '\0')
	{
		if (ft_strchr(parse, (c = BG(buff))) == NULL)
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
}
