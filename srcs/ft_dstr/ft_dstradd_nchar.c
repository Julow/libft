/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstradd_nchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:33:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:05:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

void			ft_dstradd_nchar(t_dstr *str, char c, int n)
{
	if (DSTR_NEED(str, n))
		ft_dstrextend(str, n);
	ft_memset(str->str + str->length, c, n);
	str->length += n;
	str->str[str->length] = '\0';
}
