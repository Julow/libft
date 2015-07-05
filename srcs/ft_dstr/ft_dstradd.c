/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:10:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/07/05 16:13:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstradd(t_dstr *str, char const *add, int length)
{
	if (length <= 0)
	{
		if (length == 0)
			return ;
		length += ft_strlen(add) + 1;
	}
	if (DSTR_NEED(str, length))
		ft_dstrextend(str, length);
	ft_memcpy(str->str + str->length, add, length);
	str->length += length;
	str->str[str->length] = '\0';
}
