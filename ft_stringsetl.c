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

t_bool			ft_stringsetl(t_string *str, char *set, int index, int len)
{
	int				i;

	i = index - str->length + len;
	if (i > 0)
	{
		if (!ft_stringext(str, i))
			return (FALSE);
		str->length += i;
	}
	i = -1;
	while (++i < len)
		str->content[i + index] = set[i];
	return (TRUE);
}