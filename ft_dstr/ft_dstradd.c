/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:10:39 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 12:18:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"

void			ft_dstradd(t_dstr *str, t_sub add)
{
	if (DSTR_NEED(str, add.length))
		ft_dstrextend(str, add.length);
	memcpy(str->str + str->length, add.str, add.length);
	str->length += add.length;
	str->str[str->length] = '\0';
}
