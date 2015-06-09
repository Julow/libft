/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:09:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:06:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

t_dstr			ft_dstr(char const *src, int length)
{
	t_dstr			dstr;

	if (length < 0)
		length += ft_strlen(src) + 1;
	dstr.length = length;
	dstr.capacity = MAX(length, DSTR_MIN);
	dstr.str = MAL(char, dstr.capacity + 1);
	ft_memcpy(dstr.str, src, length);
	dstr.str[length] = '\0';
	return (dstr);
}
