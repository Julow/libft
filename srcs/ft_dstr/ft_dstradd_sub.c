/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstradd_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:33:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:06:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstradd_sub(t_dstr *str, t_sub sub)
{
	if (DSTR_NEED(str, sub.length))
		ft_dstrextend(str, sub.length);
	ft_memcpy(str->str + str->length, sub.str, sub.length);
	str->length += sub.length;
	str->str[str->length] = '\0';
}
