/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:23:55 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:23:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_stringaddl(t_string *str, char *add, int len)
{
	int				i;

	if (!ft_stringext(str, len))
		return (FALSE);
	i = 0;
	while (i < len)
	{
		str->content[str->length + i] = add[i];
		i++;
	}
	str->length += len;
	return (TRUE);
}
