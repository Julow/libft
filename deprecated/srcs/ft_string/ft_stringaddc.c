/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:03:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

inline void		ft_stringaddc(t_string *str, char c)
{
	if (!ft_stringext(str, 1))
		return ;
	str->content[str->length] = c;
	str->length++;
}
