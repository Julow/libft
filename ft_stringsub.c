/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:04:18 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 19:04:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		*ft_stringsub(t_string *str, int index, int len)
{
	t_string		*sub;

	sub = ft_stringnew();
	ft_stringaddl(sub, str->content + index, len);
	return (sub);
}
