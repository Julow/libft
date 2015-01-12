/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:03:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:27:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_stringaddc(t_string *str, char c)
{
	if (!ft_stringext(str, 1))
		return ;
	str->content[str->length] = c;
	str->length++;
}
