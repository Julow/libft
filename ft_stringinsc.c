/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringinsc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:45:05 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:45:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_stringinsc(t_string *str, char c, int index)
{
	int				i;

	if (index >= str->length)
		return (ft_stringsetc(str, c, index));
	if (!ft_stringext(str, 1))
		return (FALSE);
	i = str->length - 1;
	while (--i >= index)
		str->content[i + 1] = str->content[i];
	str->content[index] = c;
	str->length++;
	return (TRUE);
}
