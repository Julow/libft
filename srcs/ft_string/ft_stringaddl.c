/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:23:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:27:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_stringaddl(t_string *str, const char *add, int len)
{
	if (!ft_stringext(str, len))
		return ;
	ft_memmove(str->content + str->length, add, len);
	str->length += len;
}
