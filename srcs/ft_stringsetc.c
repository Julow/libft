/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringsetc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:46:36 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:46:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stringsetc(t_string *str, char c, int index)
{
	if (index >= str->length)
	{
		ft_stringext(str, str->length - index + 1);
		str->length = index + 1;
	}
	str->content[index] = c;
}
