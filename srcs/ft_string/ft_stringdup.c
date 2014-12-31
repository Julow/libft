/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:19:40 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:19:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		*ft_stringdup(t_string *str)
{
	t_string		*dup;

	dup = ft_stringnew();
	if (!ft_stringext(dup, str->length))
		return (dup);
	dup->length = str->length;
	ft_memcpy(dup->content, str->content, sizeof(char) * str->length);
	return (dup);
}
