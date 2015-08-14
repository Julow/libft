/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringnews.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:54:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		*ft_stringnews(const char *s)
{
	t_string		*str;

	str = ft_stringnew();
	ft_stringadd(str, s);
	return (str);
}
