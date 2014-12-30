/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringsetl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:29:55 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:29:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stringsetl(t_string *str, const char *set, int index, int l)
{
	int				i;

	i = index - str->length + l;
	if (i > 0)
	{
		if (ft_stringext(str, i))
			str->length += i;
		else
			l = str->length - i - 1;
	}
	ft_memmove(str->content + index, set, l);
}
