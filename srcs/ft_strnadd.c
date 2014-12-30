/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:57:14 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/06 13:57:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_strnadd(char **str, char const *add, t_uint len)
{
	t_uint			lenstr;
	char			*tmp;

	tmp = *str;
	lenstr = ft_strlen(tmp);
	*str = MAL(char, lenstr + len + 1);
	if (*str == NULL)
	{
		*str = tmp;
		return ;
	}
	if (lenstr > 0)
		ft_memcpy(*str, tmp, lenstr);
	if (len > 0)
		ft_memcpy(*str, add, len);
	if (tmp != NULL)
		free(tmp);
}
