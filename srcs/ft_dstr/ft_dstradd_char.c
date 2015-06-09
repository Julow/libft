/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstradd_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:33:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:06:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstradd_char(t_dstr *str, char c)
{
	if (DSTR_NEED(str, 1))
		ft_dstrextend(str, 1);
	str->str[str->length] = c;
	str->length++;
	str->str[str->length] = '\0';
}
