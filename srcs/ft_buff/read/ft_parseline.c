/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:13:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 16:50:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parseline(t_buff *buff, t_string *dst)
{
	char			c;

	ft_stringini(dst);
	c = BG(buff);
	while (c != '\0')
	{
		if ((c = BG(buff)) == '\n' || c == '\0')
			break ;
		ft_stringaddc(dst, c);
		buff->i++;
	}
	if (c == '\n')
		buff->i++;
}
