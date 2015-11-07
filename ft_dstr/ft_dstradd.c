/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:10:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/13 20:23:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstradd(t_dstr *str, t_sub add)
{
	if (DSTR_NEED(str, add.length))
		ft_dstrextend(str, add.length);
	ft_memcpy(str->str + str->length, add.str, add.length);
	str->length += add.length;
	str->str[str->length] = '\0';
}
