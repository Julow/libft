/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:12:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:06:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstrpop(t_dstr *str, int length)
{
	if (length < 0)
		length += str->length + 1;
	str->length -= length;
	str->str[str->length] = '\0';
}
