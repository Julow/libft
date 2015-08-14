/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:58:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

t_string		*ft_stringnew(void)
{
	t_string		*str;

	str = MAL1(t_string);
	if (str == NULL)
		return (NULL);
	ft_stringini(str);
	return (str);
}
