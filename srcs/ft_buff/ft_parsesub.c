/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 17:37:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff			ft_parsesub(t_buff *buff, const char *parse)
{
	t_buff			sub;

	sub = BUFF(buff->data + buff->i, 0, 0);
	while (buff->i < buff->length)
	{
		if (ft_strchr(parse, B(buff)) == NULL)
			break ;
		buff->i++;
		sub.length++;
	}
	return (sub);
}
